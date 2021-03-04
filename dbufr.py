#!/usr/bin/env python3

import ssl

import requests
from requests.adapters import HTTPAdapter
from requests.packages.urllib3.poolmanager import PoolManager
from requests.packages.urllib3.util import ssl_


class TlsAdapter(HTTPAdapter):

    # https://stackoverflow.com/questions/44404084/python-requests-library-using-tlsv1-or-tlsv1-1-despite-upgrading-to-python-2-7

    def __init__(self, ssl_options=0, **kwargs):
        self.ssl_options = ssl_options
        super(TlsAdapter, self).__init__(**kwargs)

    def init_poolmanager(self, *pool_args, **pool_kwargs):
        ctx = ssl_.create_urllib3_context(ssl.PROTOCOL_TLS)
        ctx.options |= self.ssl_options
        self.poolmanager = PoolManager(*pool_args,
                                       ssl_context=ctx,
                                       **pool_kwargs)


def see_students_marks(id_, password):

    adapter = TlsAdapter(ssl.OP_NO_TLSv1_1 | ssl.OP_NO_TLSv1_2)

    with requests.session() as session:

        session.mount("https://", adapter)

        response = session.get(
            "https://www-dbufr.ufr-info-p6.jussieu.fr/lmd/2004/master/auths/seeStudentMarks.php",
            auth=(
                id_.encode().decode("ISO-8859-1"),
                password.encode().decode("ISO-8859-1")
            )
        )

    return response.content


if __name__ == '__main__':

    html = see_students_marks("28606523", "Pépita95!")

    print(html)
