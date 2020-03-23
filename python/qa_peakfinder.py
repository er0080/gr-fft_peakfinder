#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Copyright 2020 Eric Parent, Bitzer Scroll Inc..
#
# This is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
#
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this software; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.
#

from gnuradio import gr, gr_unittest
from gnuradio import blocks
import fft_peakfinder_swig as fft_peakfinder

class qa_peakfinder(gr_unittest.TestCase):

    def setUp(self):
        self.tb = gr.top_block()

    def tearDown(self):
        self.tb = None

    def test_001_t(self):
        src_data = (1.0, 222.7, 3.0, 4.0, 5.5, 6.0, 7.0, 200.123)
        expected_result = (222.7)
        src = blocks.vector_source_f(src_data)
        peak = fft_peakfinder.peakfinder(len(src_data))
        dst = blocks.vector_sink_f()
        self.tb.connect(src, peak)
        self.tb.connect(peak, dst)
        self.tb.run()
        result_data = dst.data()
        self.assertFloatTuplesAlmostEqual(expected_result, result_data, 6)

if __name__ == '__main__':
    gr_unittest.run(qa_peakfinder)
