#!/usr/bin/env python3

import logging
import os
import sys

import sqlite3 as sq

import config


def create_db():
    """Create the database.
    """
    if not os.path.isfile(config.DB_PATH):
        os.makedirs(config.DATA_DIR, exist_ok=True)
        try:
            connection = sq.connect(config.DB_PATH)
            cursor = connection.cursor()
            cursor.execute(config.QUERY_CREATE)
            cursor.close()
            logging.info("`{}` has been created.".format(config.DB_PATH))
        except sq.Error as error:
            logging.error(error)
        finally:
            if connection:
                connection.close()


def save(url):
    """Save an URL.
    """
    try:
        connection = sq.connect(config.DB_PATH)
        cursor = connection.cursor()
        cursor.execute(config.QUERY_INSERT, (url,))
        connection.commit()
        logging.info("`{}` saved to `{}`.".format(url, config.DB_PATH))
    except sq.IntegrityError:
        logging.info("`{}` has already been saved in {}.".format(url, config.DB_PATH))
        choice = input("Update? [Y/n]")
        if not choice or choice.strip().lower() == "y":
            update(url)
            logging.info("`{}` has been updated in {}.".format(url, config.DB_PATH))
    except sq.Error as error:
        logging.error(error)
    finally:
        if connection:
            connection.close()


def update(url):
    """Update an URL.
    """
    pass


if __name__ == "__main__":
    create_db()
    if len(sys.argv) <= 1:
        print("usage: save.py URL")
    elif len(sys.argv) == 2:
        url = sys.argv[1]
        save(url)
