# Copyright 2025 The Lynx Authors. All rights reserved.
# Licensed under the Apache License Version 2.0 that can be found in the
# LICENSE file in the root directory of this source tree.

import json

class Record:
    content = {"traceEvents":[]}
    path = None

    @staticmethod
    def record(event):
        Record.content["traceEvents"].append(event)

    @staticmethod
    def flush():
        if Record.path == None:
            return
        with open(Record.path, "w") as wf:
            json.dump(Record.content, wf)

