#!/usr/bin/env python3

import datetime
import os
import sys

import validators

from sqlitedict import SqliteDict


DB = "db.sqlite"


def init():

    with SqliteDict(DB, autocommit=True) as db:
        if "items" not in db:
            db["items"] = []


def add_url(url):

    with SqliteDict(DB) as db:
        items = db["items"]

    if url in [item["url"] for item in items if item["url"]]:
        return update_url(url)

    item = {}
    item["url"] = url
    item["redirects_to"] = None
    item["added"] = datetime.datetime.now()
    item["updated"] = None
    item["last_seen"] = item["added"]
    item["tags"] = None
    item["notes"] = None

    items.append(item)

    with SqliteDict(DB, autocommit=True) as db:
        db["items"] = items


def update_url(url):

    with SqliteDict(DB) as db:
        items = db["items"]

    for item in items:
        if item["url"] == url:
            item["updated"] = datetime.datetime.now()

    with SqliteDict(DB, autocommit=True) as db:
        db["items"] = items


if __name__ == '__main__':

    init()

    if validators.url(sys.argv[1]):
        add_url(sys.argv[1])

    with SqliteDict(DB) as db:
        print(db["items"])

