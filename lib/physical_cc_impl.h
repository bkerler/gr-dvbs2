/* -*- c++ -*- */
/* 
 * Copyright 2014,2016,2017,2020 Ron Economos.
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

#ifndef INCLUDED_DVBS2_PHYSICAL_CC_IMPL_H
#define INCLUDED_DVBS2_PHYSICAL_CC_IMPL_H

#include <dvbs2/physical_cc.h>

#define VLSNR_HEADER_LENGTH 900

namespace gr {
  namespace dvbs2 {

    class physical_cc_impl : public physical_cc
    {
     private:
      int dummy_frames;
      int b[VLSNR_HEADER_LENGTH];
      gr_complex m_bpsk[4][2];
      gr_complex m_pl[90];
      gr_complex m_pl_dummy[90];
      gr_complex m_vlsnr_header[VLSNR_HEADER_LENGTH];
      gr_complex m_zero;
      int m_cscram_x;
      int m_cscram_y;
      void b_64_8_code(unsigned char, int *);
      void pl_header_encode(unsigned char, unsigned char, int *);
      int parity_chk(int, int);
      int symbol_scrambler(void);
      void get_slots(dvbs2_framesize_t, dvbs2_code_rate_t, dvbs2_constellation_t, dvbs2_pilots_t, int, int *, int *, int *, int *);

      const static unsigned int g[7];
      const static int ph_scram_tab[64];
      const static int ph_sync_seq[26];
      const static int ph_vlsnr_seq[16][VLSNR_HEADER_LENGTH - 4];
      const static int m_cscram_root[262141 + 1];

     public:
      physical_cc_impl(dvbs2_dummy_frames_t dummyframes);
      ~physical_cc_impl();

      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items);
    };

  } // namespace dvbs2
} // namespace gr

#endif /* INCLUDED_DVBS2_PHYSICAL_CC_IMPL_H */

