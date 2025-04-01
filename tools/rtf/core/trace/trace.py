# Copyright 2025 The Lynx Authors. All rights reserved.
# Licensed under the Apache License Version 2.0 that can be found in the
# LICENSE file in the root directory of this source tree.

from core.trace.record import Record
from datetime import datetime

def get_time():
    return str(int(datetime.timestamp(datetime.now()) * 1000))


def TRACE_EVENT_BEGIN(name, args = None):
    event = {
        "name":name,
        "ph":"B",
        "ts": get_time(),
        "args": {} if args is None else args
    }
    Record.record(event)

def TRACE_EVENT_END(name, args = None):
    event = {
        "name":name,
        "ph":"E",
        "ts": get_time(),
        "args": {} if args is None else args
    }
    Record.record(event)

def TRACE_EVENT_INSTANT(args):
    if args is None:
        Log.warning(f"Trace instant event ({name}) must must hold a non-empty 'args' parameter")
    event = {
        "name":name,
        "ph":"i",
        "ts": get_time(),
        "args": {} if args is None else args
    }
    Record.record(event)