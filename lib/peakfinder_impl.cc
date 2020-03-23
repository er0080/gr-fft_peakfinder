/* -*- c++ -*- */
/*
 * Copyright 2020 Eric Parent, Bitzer Scroll Inc..
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "peakfinder_impl.h"

namespace gr {
  namespace fft_peakfinder {

    peakfinder::sptr
    peakfinder::make(size_t vlen)
    {
      return gnuradio::get_initial_sptr
        (new peakfinder_impl(vlen));
    }


    /*
     * The private constructor
     */
    peakfinder_impl::peakfinder_impl(size_t vlen)
      : gr::block("peakfinder",
              gr::io_signature::make(1, 1, vlen * sizeof(float)),
              gr::io_signature::make(1, 1, sizeof(std::int32_t))),
        d_vlen(vlen)
    {
    }

    /*
     * Our virtual destructor.
     */
    peakfinder_impl::~peakfinder_impl()
    {
    }

    void
    peakfinder_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
      ninput_items_required[0] = noutput_items;
    }

    int
    peakfinder_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      std::int32_t *out = (std::int32_t*) output_items[0];

      for (int i = 0; i < noutput_items; i++) {
        
        float max = 0.0;
        int max_idx;
        
        for (int j = 0; j < d_vlen; j++) {
          
          if (((float *)input_items[i])[j] > max) {
            max = ((float *)input_items[i])[j];
            max_idx = j;
          }
        
        }
      
        out[i] = max_idx;

      }

      consume_each (noutput_items);

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace fft_peakfinder */
} /* namespace gr */

