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

#ifndef INCLUDED_FFT_PEAKFINDER_PEAKFINDER_H
#define INCLUDED_FFT_PEAKFINDER_PEAKFINDER_H

#include <fft_peakfinder/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace fft_peakfinder {

    /*!
     * \brief <+description of block+>
     * \ingroup fft_peakfinder
     *
     */
    class FFT_PEAKFINDER_API peakfinder : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<peakfinder> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of fft_peakfinder::peakfinder.
       *
       * To avoid accidental use of raw pointers, fft_peakfinder::peakfinder's
       * constructor is in a private implementation
       * class. fft_peakfinder::peakfinder::make is the public interface for
       * creating new instances.
       */
      static sptr make(size_t vlen);
    };

  } // namespace fft_peakfinder
} // namespace gr

#endif /* INCLUDED_FFT_PEAKFINDER_PEAKFINDER_H */

