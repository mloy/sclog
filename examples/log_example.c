/*
 * SPDX-License-Identifier: MIT
 *
 * The MIT License (MIT)
 *
 * Copyright (c) <2019> <Stephan Gatzka>
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdlib.h>
#include <string.h>

#include "sclog.h"
//#include "sclog_stderr_sink.h"
#include "posix/sclog_syslog_sink.h"

int main(void)
{
	struct sc_log log;
	struct sc_log_sink sink;
	if (sc_log_syslog_sink_init(&sink, &log) == false) {
		return EXIT_FAILURE;
	}

	if (sc_log_init(&log, "log_example", SC_LOG_WARNING, &sink) == false) {
		return EXIT_FAILURE;
	}

	sc_log_message(&log, SC_LOG_ERROR, "Hello error!");
	sc_log_message(&log, SC_LOG_WARNING, "Hello warning!");
	sc_log_message(&log, SC_LOG_INFO, "Hello info!");
	sc_log_message(&log, SC_LOG_DEBUG, "Hello debug!");
	sc_log_close(&log);

	return EXIT_SUCCESS;
}