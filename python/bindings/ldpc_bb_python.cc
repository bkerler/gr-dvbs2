/*
 * Copyright 2020 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/***********************************************************************************/
/* This file is automatically generated using bindtool and can be manually edited  */
/* The following lines can be configured to regenerate this file during cmake      */
/* If manual edits are made, the following tags should be modified accordingly.    */
/* BINDTOOL_GEN_AUTOMATIC(0)                                                       */
/* BINDTOOL_USE_PYGCCXML(0)                                                        */
/* BINDTOOL_HEADER_FILE(ldpc_bb.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(98a0998650a6f303db3cf18aebea5450)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <dvbs2/ldpc_bb.h>
// pydoc.h is automatically generated in the build directory
#include <ldpc_bb_pydoc.h>

void bind_ldpc_bb(py::module& m)
{

    using ldpc_bb    = ::gr::dvbs2::ldpc_bb;


    py::class_<ldpc_bb, gr::block, gr::basic_block,
        std::shared_ptr<ldpc_bb>>(m, "ldpc_bb", D(ldpc_bb))

        .def(py::init(&ldpc_bb::make),
           D(ldpc_bb,make)
        )
        



        ;




}







