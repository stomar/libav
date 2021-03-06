/*
 *
 * This file is part of Libav.
 *
 * Libav is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * Libav is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with Libav; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef AVFILTER_BUFFERSRC_H
#define AVFILTER_BUFFERSRC_H

/**
 * @file
 * Memory buffer source API.
 */

#include "avfilter.h"

/**
 * Add a buffer to the filtergraph s.
 *
 * @param buf buffer containing frame data to be passed down the filtergraph.
 * This function will take ownership of buf, the user must not free it.
 * A NULL buf signals EOF -- i.e. no more frames will be sent to this filter.
 */
int av_buffersrc_buffer(AVFilterContext *s, AVFilterBufferRef *buf);

/**
 * Add a frame to the buffer source.
 *
 * @param s an instance of the buffersrc filter.
 * @param frame frame to be added.
 *
 * @warning frame data will be memcpy()ed, which may be a big performance
 *          hit. Use av_buffersrc_buffer() to avoid copying the data.
 */
int av_buffersrc_write_frame(AVFilterContext *s, const AVFrame *frame);

#endif /* AVFILTER_BUFFERSRC_H */
