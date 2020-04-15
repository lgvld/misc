import logging
import os
import sys

DATA_DIR = "data"

DB_NAME = "db.sqlite"
DB_PATH = os.path.join(DATA_DIR, DB_NAME)
QUERY_CREATE = """CREATE TABLE links
    (
        url TEXT PRIMARY KEY
    )
    WITHOUT ROWID;
"""
QUERY_INSERT = """INSERT INTO links
    (
        url
    )
    VALUES (?)
"""

logging.basicConfig(
    # filename="log.txt",
    # filemode="w",
    stream=sys.stdout,
    level=logging.DEBUG,
    format="%(levelname)s:%(message)s"
)
