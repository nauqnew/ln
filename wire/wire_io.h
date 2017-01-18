#ifndef LIGHTNING_WIRE_WIRE_IO_H
#define LIGHTNING_WIRE_WIRE_IO_H
#include "config.h"
#include <ccan/io/io.h>
#include <ccan/short_types/short_types.h>

/* Read message into *data, allocating off ctx. */
struct io_plan *io_read_wire_(struct io_conn *conn,
			      const tal_t *ctx,
			      u8 **data,
			      struct io_plan *(*next)(struct io_conn *, void *),
			      void *next_arg);

#define io_read_wire(conn, ctx, data, next, arg)			\
	io_read_wire_((conn), (ctx), (data),				\
		      typesafe_cb_preargs(struct io_plan *, void *,	\
					  (next), (arg), struct io_conn *), \
		      (arg))

/* Write message from data (tal_count(data) gives length). */
struct io_plan *io_write_wire_(struct io_conn *conn,
			       const u8 *data,
			       struct io_plan *(*next)(struct io_conn *, void *),
			       void *next_arg);

#define io_write_wire(conn, data, next, arg)				\
	io_write_wire_((conn), (data),					\
		       typesafe_cb_preargs(struct io_plan *, void *,	\
					   (next), (arg), struct io_conn *), \
		       (arg))
#endif /* LIGHTNING_WIRE_WIRE_IO_H */
