#!/usr/bin/env python3

import collections
import json
import pprint
import os

from tika import parser

DIR_BOOKS = "books/"

books = [b for b in os.listdir(DIR_BOOKS) if b.endswith(".pdf")]

pp = pprint.PrettyPrinter(indent=4)

for book in books:
    book = os.path.join(DIR_BOOKS, book)
    if os.path.isfile(book + ".data"):
        with open(book + ".data", "r") as stream:
            data = json.load(stream)
    else:
        data = parser.from_file(book)
        with open(book + ".data", "w") as stream:
            json.dump(data, stream, indent=4)
    # pp.pprint(data["content"])
    words = list(data["content"].split())
    wc = collections.Counter(words)
    # pp.pprint(words)
    top_words = {k: v for k, v in wc.items() if len(k) > 2 and v > 10}
    top_words = sorted(top_words.items(), key=lambda x: x[1], reverse=True)
    # pp.pprint(top_words)
    for k, v in top_words:
        print(k, v)
