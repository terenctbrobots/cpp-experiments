# Makefile.in generated by automake 1.16.1 from Makefile.am.
# include/Makefile.  Generated from Makefile.in by configure.

# Copyright (C) 1994-2018 Free Software Foundation, Inc.

# This Makefile.in is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY, to the extent permitted by law; without
# even the implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE.




am__is_gnu_make = { \
  if test -z '$(MAKELEVEL)'; then \
    false; \
  elif test -n '$(MAKE_HOST)'; then \
    true; \
  elif test -n '$(MAKE_VERSION)' && test -n '$(CURDIR)'; then \
    true; \
  else \
    false; \
  fi; \
}
am__make_running_with_option = \
  case $${target_option-} in \
      ?) ;; \
      *) echo "am__make_running_with_option: internal error: invalid" \
              "target option '$${target_option-}' specified" >&2; \
         exit 1;; \
  esac; \
  has_opt=no; \
  sane_makeflags=$$MAKEFLAGS; \
  if $(am__is_gnu_make); then \
    sane_makeflags=$$MFLAGS; \
  else \
    case $$MAKEFLAGS in \
      *\\[\ \	]*) \
        bs=\\; \
        sane_makeflags=`printf '%s\n' "$$MAKEFLAGS" \
          | sed "s/$$bs$$bs[$$bs $$bs	]*//g"`;; \
    esac; \
  fi; \
  skip_next=no; \
  strip_trailopt () \
  { \
    flg=`printf '%s\n' "$$flg" | sed "s/$$1.*$$//"`; \
  }; \
  for flg in $$sane_makeflags; do \
    test $$skip_next = yes && { skip_next=no; continue; }; \
    case $$flg in \
      *=*|--*) continue;; \
        -*I) strip_trailopt 'I'; skip_next=yes;; \
      -*I?*) strip_trailopt 'I';; \
        -*O) strip_trailopt 'O'; skip_next=yes;; \
      -*O?*) strip_trailopt 'O';; \
        -*l) strip_trailopt 'l'; skip_next=yes;; \
      -*l?*) strip_trailopt 'l';; \
      -[dEDm]) skip_next=yes;; \
      -[JT]) skip_next=yes;; \
    esac; \
    case $$flg in \
      *$$target_option*) has_opt=yes; break;; \
    esac; \
  done; \
  test $$has_opt = yes
am__make_dryrun = (target_option=n; $(am__make_running_with_option))
am__make_keepgoing = (target_option=k; $(am__make_running_with_option))
pkgdatadir = $(datadir)/asio
pkgincludedir = $(includedir)/asio
pkglibdir = $(libdir)/asio
pkglibexecdir = $(libexecdir)/asio
am__cd = CDPATH="$${ZSH_VERSION+.}$(PATH_SEPARATOR)" && cd
install_sh_DATA = $(install_sh) -c -m 644
install_sh_PROGRAM = $(install_sh) -c
install_sh_SCRIPT = $(install_sh) -c
INSTALL_HEADER = $(INSTALL_DATA)
transform = $(program_transform_name)
NORMAL_INSTALL = :
PRE_INSTALL = :
POST_INSTALL = :
NORMAL_UNINSTALL = :
PRE_UNINSTALL = :
POST_UNINSTALL = :
build_triplet = x86_64-pc-linux-gnu
host_triplet = x86_64-pc-linux-gnu
subdir = include
ACLOCAL_M4 = $(top_srcdir)/aclocal.m4
am__aclocal_m4_deps = $(top_srcdir)/configure.ac
am__configure_deps = $(am__aclocal_m4_deps) $(CONFIGURE_DEPENDENCIES) \
	$(ACLOCAL_M4)
DIST_COMMON = $(srcdir)/Makefile.am $(nobase_include_HEADERS) \
	$(am__DIST_COMMON)
mkinstalldirs = $(install_sh) -d
CONFIG_CLEAN_FILES =
CONFIG_CLEAN_VPATH_FILES =
AM_V_P = $(am__v_P_$(V))
am__v_P_ = $(am__v_P_$(AM_DEFAULT_VERBOSITY))
am__v_P_0 = false
am__v_P_1 = :
AM_V_GEN = $(am__v_GEN_$(V))
am__v_GEN_ = $(am__v_GEN_$(AM_DEFAULT_VERBOSITY))
am__v_GEN_0 = @echo "  GEN     " $@;
am__v_GEN_1 = 
AM_V_at = $(am__v_at_$(V))
am__v_at_ = $(am__v_at_$(AM_DEFAULT_VERBOSITY))
am__v_at_0 = @
am__v_at_1 = 
SOURCES =
DIST_SOURCES =
am__can_run_installinfo = \
  case $$AM_UPDATE_INFO_DIR in \
    n|no|NO) false;; \
    *) (install-info --version) >/dev/null 2>&1;; \
  esac
am__vpath_adj_setup = srcdirstrip=`echo "$(srcdir)" | sed 's|.|.|g'`;
am__vpath_adj = case $$p in \
    $(srcdir)/*) f=`echo "$$p" | sed "s|^$$srcdirstrip/||"`;; \
    *) f=$$p;; \
  esac;
am__strip_dir = f=`echo $$p | sed -e 's|^.*/||'`;
am__install_max = 40
am__nobase_strip_setup = \
  srcdirstrip=`echo "$(srcdir)" | sed 's/[].[^$$\\*|]/\\\\&/g'`
am__nobase_strip = \
  for p in $$list; do echo "$$p"; done | sed -e "s|$$srcdirstrip/||"
am__nobase_list = $(am__nobase_strip_setup); \
  for p in $$list; do echo "$$p $$p"; done | \
  sed "s| $$srcdirstrip/| |;"' / .*\//!s/ .*/ ./; s,\( .*\)/[^/]*$$,\1,' | \
  $(AWK) 'BEGIN { files["."] = "" } { files[$$2] = files[$$2] " " $$1; \
    if (++n[$$2] == $(am__install_max)) \
      { print $$2, files[$$2]; n[$$2] = 0; files[$$2] = "" } } \
    END { for (dir in files) print dir, files[dir] }'
am__base_list = \
  sed '$$!N;$$!N;$$!N;$$!N;$$!N;$$!N;$$!N;s/\n/ /g' | \
  sed '$$!N;$$!N;$$!N;$$!N;s/\n/ /g'
am__uninstall_files_from_dir = { \
  test -z "$$files" \
    || { test ! -d "$$dir" && test ! -f "$$dir" && test ! -r "$$dir"; } \
    || { echo " ( cd '$$dir' && rm -f" $$files ")"; \
         $(am__cd) "$$dir" && rm -f $$files; }; \
  }
am__installdirs = "$(DESTDIR)$(includedir)"
HEADERS = $(nobase_include_HEADERS)
am__tagged_files = $(HEADERS) $(SOURCES) $(TAGS_FILES) $(LISP)
# Read a list of newline-separated strings from the standard input,
# and print each of them once, without duplicates.  Input order is
# *not* preserved.
am__uniquify_input = $(AWK) '\
  BEGIN { nonempty = 0; } \
  { items[$$0] = 1; nonempty = 1; } \
  END { if (nonempty) { for (i in items) print i; }; } \
'
# Make sure the list of sources is unique.  This is necessary because,
# e.g., the same source file might be shared among _SOURCES variables
# for different programs/libraries.
am__define_uniq_tagged_files = \
  list='$(am__tagged_files)'; \
  unique=`for i in $$list; do \
    if test -f "$$i"; then echo $$i; else echo $(srcdir)/$$i; fi; \
  done | $(am__uniquify_input)`
ETAGS = etags
CTAGS = ctags
am__DIST_COMMON = $(srcdir)/Makefile.in
DISTFILES = $(DIST_COMMON) $(DIST_SOURCES) $(TEXINFOS) $(EXTRA_DIST)
ACLOCAL = ${SHELL} /home/terenctb/project/bigbadrobots/cpp-experiments/asio/missing aclocal-1.16
AMTAR = $${TAR-tar}
AM_DEFAULT_VERBOSITY = 1
AUTOCONF = ${SHELL} /home/terenctb/project/bigbadrobots/cpp-experiments/asio/missing autoconf
AUTOHEADER = ${SHELL} /home/terenctb/project/bigbadrobots/cpp-experiments/asio/missing autoheader
AUTOMAKE = ${SHELL} /home/terenctb/project/bigbadrobots/cpp-experiments/asio/missing automake-1.16
AWK = gawk
CC = gcc
CCDEPMODE = depmode=gcc3
CFLAGS = -g -O2
CPPFLAGS =  -DASIO_STANDALONE
CXX = g++
CXXCPP = 
CXXDEPMODE = depmode=gcc3
CXXFLAGS = -g -O2 -pthread -ftemplate-depth-256
CYGPATH_W = echo
DEFS = -DPACKAGE_NAME=\"asio\" -DPACKAGE_TARNAME=\"asio\" -DPACKAGE_VERSION=\"1.12.2\" -DPACKAGE_STRING=\"asio\ 1.12.2\" -DPACKAGE_BUGREPORT=\"\" -DPACKAGE_URL=\"\" -DPACKAGE=\"asio\" -DVERSION=\"1.12.2\" -D_REENTRANT=1
DEPDIR = .deps
ECHO_C = 
ECHO_N = -n
ECHO_T = 
EGREP = 
EXEEXT = 
GREP = 
INSTALL = /usr/bin/install -c
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_PROGRAM = ${INSTALL}
INSTALL_SCRIPT = ${INSTALL}
INSTALL_STRIP_PROGRAM = $(install_sh) -c -s
LDFLAGS =  -pthread
LIBOBJS = 
LIBS =  -lrt
LTLIBOBJS = 
MAINT = #
MAKEINFO = ${SHELL} /home/terenctb/project/bigbadrobots/cpp-experiments/asio/missing makeinfo
MKDIR_P = /usr/bin/mkdir -p
OBJEXT = o
PACKAGE = asio
PACKAGE_BUGREPORT = 
PACKAGE_NAME = asio
PACKAGE_STRING = asio 1.12.2
PACKAGE_TARNAME = asio
PACKAGE_URL = 
PACKAGE_VERSION = 1.12.2
PATH_SEPARATOR = :
RANLIB = ranlib
SET_MAKE = 
SHELL = /bin/sh
STRIP = 
VERSION = 1.12.2
abs_builddir = /home/terenctb/project/bigbadrobots/cpp-experiments/asio/include
abs_srcdir = /home/terenctb/project/bigbadrobots/cpp-experiments/asio/include
abs_top_builddir = /home/terenctb/project/bigbadrobots/cpp-experiments/asio
abs_top_srcdir = /home/terenctb/project/bigbadrobots/cpp-experiments/asio
ac_ct_CC = gcc
ac_ct_CXX = g++
am__include = include
am__leading_dot = .
am__quote = 
am__tar = tar --format=ustar -chf - "$$tardir"
am__untar = tar -xf -
bindir = ${exec_prefix}/bin
build = x86_64-pc-linux-gnu
build_alias = 
build_cpu = x86_64
build_os = linux-gnu
build_vendor = pc
builddir = .
datadir = ${datarootdir}
datarootdir = ${prefix}/share
docdir = ${datarootdir}/doc/${PACKAGE_TARNAME}
dvidir = ${docdir}
exec_prefix = ${prefix}
host = x86_64-pc-linux-gnu
host_alias = 
host_cpu = x86_64
host_os = linux-gnu
host_vendor = pc
htmldir = ${docdir}
includedir = ${prefix}/include
infodir = ${datarootdir}/info
install_sh = ${SHELL} /home/terenctb/project/bigbadrobots/cpp-experiments/asio/install-sh
libdir = ${exec_prefix}/lib
libexecdir = ${exec_prefix}/libexec
localedir = ${datarootdir}/locale
localstatedir = ${prefix}/var
mandir = ${datarootdir}/man
mkdir_p = $(MKDIR_P)
oldincludedir = /usr/include
pdfdir = ${docdir}
prefix = /usr/local
program_transform_name = s,x,x,
psdir = ${docdir}
sbindir = ${exec_prefix}/sbin
sharedstatedir = ${prefix}/com
srcdir = .
sysconfdir = ${prefix}/etc
target_alias = 
top_build_prefix = ../
top_builddir = ..
top_srcdir = ..

# find . -name "*.*pp" | sed -e 's/^\.\///' | sed -e 's/^.*$/  & \\/' | sort
nobase_include_HEADERS = \
	asio/associated_allocator.hpp \
	asio/associated_executor.hpp \
	asio/async_result.hpp \
	asio/basic_datagram_socket.hpp \
	asio/basic_deadline_timer.hpp \
	asio/basic_io_object.hpp \
	asio/basic_raw_socket.hpp \
	asio/basic_seq_packet_socket.hpp \
	asio/basic_serial_port.hpp \
	asio/basic_signal_set.hpp \
	asio/basic_socket_acceptor.hpp \
	asio/basic_socket.hpp \
	asio/basic_socket_iostream.hpp \
	asio/basic_socket_streambuf.hpp \
	asio/basic_streambuf_fwd.hpp \
	asio/basic_streambuf.hpp \
	asio/basic_stream_socket.hpp \
	asio/basic_waitable_timer.hpp \
	asio/bind_executor.hpp \
	asio/buffered_read_stream_fwd.hpp \
	asio/buffered_read_stream.hpp \
	asio/buffered_stream_fwd.hpp \
	asio/buffered_stream.hpp \
	asio/buffered_write_stream_fwd.hpp \
	asio/buffered_write_stream.hpp \
	asio/buffer.hpp \
	asio/buffers_iterator.hpp \
	asio/completion_condition.hpp \
	asio/connect.hpp \
	asio/coroutine.hpp \
	asio/datagram_socket_service.hpp \
	asio/deadline_timer.hpp \
	asio/deadline_timer_service.hpp \
	asio/defer.hpp \
	asio/detail/array_fwd.hpp \
	asio/detail/array.hpp \
	asio/detail/assert.hpp \
	asio/detail/atomic_count.hpp \
	asio/detail/base_from_completion_cond.hpp \
	asio/detail/bind_handler.hpp \
	asio/detail/buffered_stream_storage.hpp \
	asio/detail/buffer_resize_guard.hpp \
	asio/detail/buffer_sequence_adapter.hpp \
	asio/detail/call_stack.hpp \
	asio/detail/chrono.hpp \
	asio/detail/chrono_time_traits.hpp \
	asio/detail/completion_handler.hpp \
	asio/detail/concurrency_hint.hpp \
	asio/detail/conditionally_enabled_event.hpp \
	asio/detail/conditionally_enabled_mutex.hpp \
	asio/detail/config.hpp \
	asio/detail/consuming_buffers.hpp \
	asio/detail/cstddef.hpp \
	asio/detail/cstdint.hpp \
	asio/detail/date_time_fwd.hpp \
	asio/detail/deadline_timer_service.hpp \
	asio/detail/dependent_type.hpp \
	asio/detail/descriptor_ops.hpp \
	asio/detail/descriptor_read_op.hpp \
	asio/detail/descriptor_write_op.hpp \
	asio/detail/dev_poll_reactor.hpp \
	asio/detail/epoll_reactor.hpp \
	asio/detail/eventfd_select_interrupter.hpp \
	asio/detail/event.hpp \
	asio/detail/executor_op.hpp \
	asio/detail/fd_set_adapter.hpp \
	asio/detail/fenced_block.hpp \
	asio/detail/functional.hpp \
	asio/detail/future.hpp \
	asio/detail/gcc_arm_fenced_block.hpp \
	asio/detail/gcc_hppa_fenced_block.hpp \
	asio/detail/gcc_sync_fenced_block.hpp \
	asio/detail/gcc_x86_fenced_block.hpp \
	asio/detail/global.hpp \
	asio/detail/handler_alloc_helpers.hpp \
	asio/detail/handler_cont_helpers.hpp \
	asio/detail/handler_invoke_helpers.hpp \
	asio/detail/handler_tracking.hpp \
	asio/detail/handler_type_requirements.hpp \
	asio/detail/handler_work.hpp \
	asio/detail/hash_map.hpp \
	asio/detail/impl/buffer_sequence_adapter.ipp \
	asio/detail/impl/descriptor_ops.ipp \
	asio/detail/impl/dev_poll_reactor.hpp \
	asio/detail/impl/dev_poll_reactor.ipp \
	asio/detail/impl/epoll_reactor.hpp \
	asio/detail/impl/epoll_reactor.ipp \
	asio/detail/impl/eventfd_select_interrupter.ipp \
	asio/detail/impl/handler_tracking.ipp \
	asio/detail/impl/kqueue_reactor.hpp \
	asio/detail/impl/kqueue_reactor.ipp \
	asio/detail/impl/null_event.ipp \
	asio/detail/impl/pipe_select_interrupter.ipp \
	asio/detail/impl/posix_event.ipp \
	asio/detail/impl/posix_mutex.ipp \
	asio/detail/impl/posix_thread.ipp \
	asio/detail/impl/posix_tss_ptr.ipp \
	asio/detail/impl/reactive_descriptor_service.ipp \
	asio/detail/impl/reactive_serial_port_service.ipp \
	asio/detail/impl/reactive_socket_service_base.ipp \
	asio/detail/impl/resolver_service_base.ipp \
	asio/detail/impl/scheduler.ipp \
	asio/detail/impl/select_reactor.hpp \
	asio/detail/impl/select_reactor.ipp \
	asio/detail/impl/service_registry.hpp \
	asio/detail/impl/service_registry.ipp \
	asio/detail/impl/signal_set_service.ipp \
	asio/detail/impl/socket_ops.ipp \
	asio/detail/impl/socket_select_interrupter.ipp \
	asio/detail/impl/strand_executor_service.hpp \
	asio/detail/impl/strand_executor_service.ipp \
	asio/detail/impl/strand_service.hpp \
	asio/detail/impl/strand_service.ipp \
	asio/detail/impl/throw_error.ipp \
	asio/detail/impl/timer_queue_ptime.ipp \
	asio/detail/impl/timer_queue_set.ipp \
	asio/detail/impl/win_event.ipp \
	asio/detail/impl/win_iocp_handle_service.ipp \
	asio/detail/impl/win_iocp_io_context.hpp \
	asio/detail/impl/win_iocp_io_context.ipp \
	asio/detail/impl/win_iocp_serial_port_service.ipp \
	asio/detail/impl/win_iocp_socket_service_base.ipp \
	asio/detail/impl/win_mutex.ipp \
	asio/detail/impl/win_object_handle_service.ipp \
	asio/detail/impl/winrt_ssocket_service_base.ipp \
	asio/detail/impl/winrt_timer_scheduler.hpp \
	asio/detail/impl/winrt_timer_scheduler.ipp \
	asio/detail/impl/winsock_init.ipp \
	asio/detail/impl/win_static_mutex.ipp \
	asio/detail/impl/win_thread.ipp \
	asio/detail/impl/win_tss_ptr.ipp \
	asio/detail/io_control.hpp \
	asio/detail/is_buffer_sequence.hpp \
	asio/detail/is_executor.hpp \
	asio/detail/keyword_tss_ptr.hpp \
	asio/detail/kqueue_reactor.hpp \
	asio/detail/limits.hpp \
	asio/detail/local_free_on_block_exit.hpp \
	asio/detail/macos_fenced_block.hpp \
	asio/detail/memory.hpp \
	asio/detail/mutex.hpp \
	asio/detail/noncopyable.hpp \
	asio/detail/null_event.hpp \
	asio/detail/null_fenced_block.hpp \
	asio/detail/null_global.hpp \
	asio/detail/null_mutex.hpp \
	asio/detail/null_reactor.hpp \
	asio/detail/null_signal_blocker.hpp \
	asio/detail/null_socket_service.hpp \
	asio/detail/null_static_mutex.hpp \
	asio/detail/null_thread.hpp \
	asio/detail/null_tss_ptr.hpp \
	asio/detail/object_pool.hpp \
	asio/detail/old_win_sdk_compat.hpp \
	asio/detail/operation.hpp \
	asio/detail/op_queue.hpp \
	asio/detail/pipe_select_interrupter.hpp \
	asio/detail/pop_options.hpp \
	asio/detail/posix_event.hpp \
	asio/detail/posix_fd_set_adapter.hpp \
	asio/detail/posix_global.hpp \
	asio/detail/posix_mutex.hpp \
	asio/detail/posix_signal_blocker.hpp \
	asio/detail/posix_static_mutex.hpp \
	asio/detail/posix_thread.hpp \
	asio/detail/posix_tss_ptr.hpp \
	asio/detail/push_options.hpp \
	asio/detail/reactive_descriptor_service.hpp \
	asio/detail/reactive_null_buffers_op.hpp \
	asio/detail/reactive_serial_port_service.hpp \
	asio/detail/reactive_socket_accept_op.hpp \
	asio/detail/reactive_socket_connect_op.hpp \
	asio/detail/reactive_socket_recvfrom_op.hpp \
	asio/detail/reactive_socket_recvmsg_op.hpp \
	asio/detail/reactive_socket_recv_op.hpp \
	asio/detail/reactive_socket_send_op.hpp \
	asio/detail/reactive_socket_sendto_op.hpp \
	asio/detail/reactive_socket_service_base.hpp \
	asio/detail/reactive_socket_service.hpp \
	asio/detail/reactive_wait_op.hpp \
	asio/detail/reactor_fwd.hpp \
	asio/detail/reactor.hpp \
	asio/detail/reactor_op.hpp \
	asio/detail/reactor_op_queue.hpp \
	asio/detail/recycling_allocator.hpp \
	asio/detail/regex_fwd.hpp \
	asio/detail/resolve_endpoint_op.hpp \
	asio/detail/resolve_op.hpp \
	asio/detail/resolve_query_op.hpp \
	asio/detail/resolver_service_base.hpp \
	asio/detail/resolver_service.hpp \
	asio/detail/scheduler.hpp \
	asio/detail/scheduler_operation.hpp \
	asio/detail/scheduler_thread_info.hpp \
	asio/detail/scoped_lock.hpp \
	asio/detail/scoped_ptr.hpp \
	asio/detail/select_interrupter.hpp \
	asio/detail/select_reactor.hpp \
	asio/detail/service_registry.hpp \
	asio/detail/signal_blocker.hpp \
	asio/detail/signal_handler.hpp \
	asio/detail/signal_init.hpp \
	asio/detail/signal_op.hpp \
	asio/detail/signal_set_service.hpp \
	asio/detail/socket_holder.hpp \
	asio/detail/socket_ops.hpp \
	asio/detail/socket_option.hpp \
	asio/detail/socket_select_interrupter.hpp \
	asio/detail/socket_types.hpp \
	asio/detail/solaris_fenced_block.hpp \
	asio/detail/static_mutex.hpp \
	asio/detail/std_event.hpp \
	asio/detail/std_fenced_block.hpp \
	asio/detail/std_global.hpp \
	asio/detail/std_mutex.hpp \
	asio/detail/std_static_mutex.hpp \
	asio/detail/std_thread.hpp \
	asio/detail/strand_executor_service.hpp \
	asio/detail/strand_service.hpp \
	asio/detail/string_view.hpp \
	asio/detail/thread_context.hpp \
	asio/detail/thread_group.hpp \
	asio/detail/thread.hpp \
	asio/detail/thread_info_base.hpp \
	asio/detail/throw_error.hpp \
	asio/detail/throw_exception.hpp \
	asio/detail/timer_queue_base.hpp \
	asio/detail/timer_queue.hpp \
	asio/detail/timer_queue_ptime.hpp \
	asio/detail/timer_queue_set.hpp \
	asio/detail/timer_scheduler_fwd.hpp \
	asio/detail/timer_scheduler.hpp \
	asio/detail/tss_ptr.hpp \
	asio/detail/type_traits.hpp \
	asio/detail/variadic_templates.hpp \
	asio/detail/wait_handler.hpp \
	asio/detail/wait_op.hpp \
	asio/detail/winapp_thread.hpp \
	asio/detail/wince_thread.hpp \
	asio/detail/win_event.hpp \
	asio/detail/win_fd_set_adapter.hpp \
	asio/detail/win_fenced_block.hpp \
	asio/detail/win_global.hpp \
	asio/detail/win_iocp_handle_read_op.hpp \
	asio/detail/win_iocp_handle_service.hpp \
	asio/detail/win_iocp_handle_write_op.hpp \
	asio/detail/win_iocp_io_context.hpp \
	asio/detail/win_iocp_null_buffers_op.hpp \
	asio/detail/win_iocp_operation.hpp \
	asio/detail/win_iocp_overlapped_op.hpp \
	asio/detail/win_iocp_overlapped_ptr.hpp \
	asio/detail/win_iocp_serial_port_service.hpp \
	asio/detail/win_iocp_socket_accept_op.hpp \
	asio/detail/win_iocp_socket_connect_op.hpp \
	asio/detail/win_iocp_socket_recvfrom_op.hpp \
	asio/detail/win_iocp_socket_recvmsg_op.hpp \
	asio/detail/win_iocp_socket_recv_op.hpp \
	asio/detail/win_iocp_socket_send_op.hpp \
	asio/detail/win_iocp_socket_service_base.hpp \
	asio/detail/win_iocp_socket_service.hpp \
	asio/detail/win_iocp_thread_info.hpp \
	asio/detail/win_iocp_wait_op.hpp \
	asio/detail/win_mutex.hpp \
	asio/detail/win_object_handle_service.hpp \
	asio/detail/winrt_async_manager.hpp \
	asio/detail/winrt_async_op.hpp \
	asio/detail/winrt_resolve_op.hpp \
	asio/detail/winrt_resolver_service.hpp \
	asio/detail/winrt_socket_connect_op.hpp \
	asio/detail/winrt_socket_recv_op.hpp \
	asio/detail/winrt_socket_send_op.hpp \
	asio/detail/winrt_ssocket_service_base.hpp \
	asio/detail/winrt_ssocket_service.hpp \
	asio/detail/winrt_timer_scheduler.hpp \
	asio/detail/winrt_utils.hpp \
	asio/detail/winsock_init.hpp \
	asio/detail/win_static_mutex.hpp \
	asio/detail/win_thread.hpp \
	asio/detail/win_tss_ptr.hpp \
	asio/detail/work_dispatcher.hpp \
	asio/detail/wrapped_handler.hpp \
	asio/dispatch.hpp \
	asio/error_code.hpp \
	asio/error.hpp \
	asio/execution_context.hpp \
	asio/executor.hpp \
	asio/executor_work_guard.hpp \
	asio/experimental/co_spawn.hpp \
	asio/experimental/detached.hpp \
	asio/experimental.hpp \
	asio/experimental/impl/co_spawn.hpp \
	asio/experimental/impl/detached.hpp \
	asio/experimental/impl/redirect_error.hpp \
	asio/experimental/redirect_error.hpp \
	asio/generic/basic_endpoint.hpp \
	asio/generic/datagram_protocol.hpp \
	asio/generic/detail/endpoint.hpp \
	asio/generic/detail/impl/endpoint.ipp \
	asio/generic/raw_protocol.hpp \
	asio/generic/seq_packet_protocol.hpp \
	asio/generic/stream_protocol.hpp \
	asio/handler_alloc_hook.hpp \
	asio/handler_continuation_hook.hpp \
	asio/handler_invoke_hook.hpp \
	asio/handler_type.hpp \
	asio/high_resolution_timer.hpp \
	asio.hpp \
	asio/impl/buffered_read_stream.hpp \
	asio/impl/buffered_write_stream.hpp \
	asio/impl/connect.hpp \
	asio/impl/defer.hpp \
	asio/impl/dispatch.hpp \
	asio/impl/error_code.ipp \
	asio/impl/error.ipp \
	asio/impl/execution_context.hpp \
	asio/impl/execution_context.ipp \
	asio/impl/executor.hpp \
	asio/impl/executor.ipp \
	asio/impl/handler_alloc_hook.ipp \
	asio/impl/io_context.hpp \
	asio/impl/io_context.ipp \
	asio/impl/post.hpp \
	asio/impl/read_at.hpp \
	asio/impl/read.hpp \
	asio/impl/read_until.hpp \
	asio/impl/serial_port_base.hpp \
	asio/impl/serial_port_base.ipp \
	asio/impl/spawn.hpp \
	asio/impl/src.cpp \
	asio/impl/src.hpp \
	asio/impl/system_context.hpp \
	asio/impl/system_context.ipp \
	asio/impl/system_executor.hpp \
	asio/impl/thread_pool.hpp \
	asio/impl/thread_pool.ipp \
	asio/impl/use_future.hpp \
	asio/impl/write_at.hpp \
	asio/impl/write.hpp \
	asio/io_context.hpp \
	asio/io_context_strand.hpp \
	asio/io_service.hpp \
	asio/io_service_strand.hpp \
	asio/ip/address.hpp \
	asio/ip/address_v4.hpp \
	asio/ip/address_v4_iterator.hpp \
	asio/ip/address_v4_range.hpp \
	asio/ip/address_v6.hpp \
	asio/ip/address_v6_iterator.hpp \
	asio/ip/address_v6_range.hpp \
	asio/ip/bad_address_cast.hpp \
	asio/ip/basic_endpoint.hpp \
	asio/ip/basic_resolver_entry.hpp \
	asio/ip/basic_resolver.hpp \
	asio/ip/basic_resolver_iterator.hpp \
	asio/ip/basic_resolver_query.hpp \
	asio/ip/basic_resolver_results.hpp \
	asio/ip/detail/endpoint.hpp \
	asio/ip/detail/impl/endpoint.ipp \
	asio/ip/detail/socket_option.hpp \
	asio/ip/host_name.hpp \
	asio/ip/icmp.hpp \
	asio/ip/impl/address.hpp \
	asio/ip/impl/address.ipp \
	asio/ip/impl/address_v4.hpp \
	asio/ip/impl/address_v4.ipp \
	asio/ip/impl/address_v6.hpp \
	asio/ip/impl/address_v6.ipp \
	asio/ip/impl/basic_endpoint.hpp \
	asio/ip/impl/host_name.ipp \
	asio/ip/impl/network_v4.hpp \
	asio/ip/impl/network_v4.ipp \
	asio/ip/impl/network_v6.hpp \
	asio/ip/impl/network_v6.ipp \
	asio/ip/multicast.hpp \
	asio/ip/network_v4.hpp \
	asio/ip/network_v6.hpp \
	asio/ip/resolver_base.hpp \
	asio/ip/resolver_query_base.hpp \
	asio/ip/resolver_service.hpp \
	asio/ip/tcp.hpp \
	asio/ip/udp.hpp \
	asio/ip/unicast.hpp \
	asio/ip/v6_only.hpp \
	asio/is_executor.hpp \
	asio/is_read_buffered.hpp \
	asio/is_write_buffered.hpp \
	asio/local/basic_endpoint.hpp \
	asio/local/connect_pair.hpp \
	asio/local/datagram_protocol.hpp \
	asio/local/detail/endpoint.hpp \
	asio/local/detail/impl/endpoint.ipp \
	asio/local/stream_protocol.hpp \
	asio/packaged_task.hpp \
	asio/placeholders.hpp \
	asio/posix/basic_descriptor.hpp \
	asio/posix/basic_stream_descriptor.hpp \
	asio/posix/descriptor_base.hpp \
	asio/posix/descriptor.hpp \
	asio/posix/stream_descriptor.hpp \
	asio/posix/stream_descriptor_service.hpp \
	asio/post.hpp \
	asio/raw_socket_service.hpp \
	asio/read_at.hpp \
	asio/read.hpp \
	asio/read_until.hpp \
	asio/seq_packet_socket_service.hpp \
	asio/serial_port_base.hpp \
	asio/serial_port.hpp \
	asio/serial_port_service.hpp \
	asio/signal_set.hpp \
	asio/signal_set_service.hpp \
	asio/socket_acceptor_service.hpp \
	asio/socket_base.hpp \
	asio/spawn.hpp \
	asio/ssl/context_base.hpp \
	asio/ssl/context.hpp \
	asio/ssl/detail/buffered_handshake_op.hpp \
	asio/ssl/detail/engine.hpp \
	asio/ssl/detail/handshake_op.hpp \
	asio/ssl/detail/impl/engine.ipp \
	asio/ssl/detail/impl/openssl_init.ipp \
	asio/ssl/detail/io.hpp \
	asio/ssl/detail/openssl_init.hpp \
	asio/ssl/detail/openssl_types.hpp \
	asio/ssl/detail/password_callback.hpp \
	asio/ssl/detail/read_op.hpp \
	asio/ssl/detail/shutdown_op.hpp \
	asio/ssl/detail/stream_core.hpp \
	asio/ssl/detail/verify_callback.hpp \
	asio/ssl/detail/write_op.hpp \
	asio/ssl/error.hpp \
	asio/ssl.hpp \
	asio/ssl/impl/context.hpp \
	asio/ssl/impl/context.ipp \
	asio/ssl/impl/error.ipp \
	asio/ssl/impl/rfc2818_verification.ipp \
	asio/ssl/impl/src.hpp \
	asio/ssl/rfc2818_verification.hpp \
	asio/ssl/stream_base.hpp \
	asio/ssl/stream.hpp \
	asio/ssl/verify_context.hpp \
	asio/ssl/verify_mode.hpp \
	asio/steady_timer.hpp \
	asio/strand.hpp \
	asio/streambuf.hpp \
	asio/stream_socket_service.hpp \
	asio/system_context.hpp \
	asio/system_error.hpp \
	asio/system_executor.hpp \
	asio/system_timer.hpp \
	asio/thread.hpp \
	asio/thread_pool.hpp \
	asio/time_traits.hpp \
	asio/ts/buffer.hpp \
	asio/ts/executor.hpp \
	asio/ts/internet.hpp \
	asio/ts/io_context.hpp \
	asio/ts/netfwd.hpp \
	asio/ts/net.hpp \
	asio/ts/socket.hpp \
	asio/ts/timer.hpp \
	asio/unyield.hpp \
	asio/use_future.hpp \
	asio/uses_executor.hpp \
	asio/version.hpp \
	asio/waitable_timer_service.hpp \
	asio/wait_traits.hpp \
	asio/windows/basic_handle.hpp \
	asio/windows/basic_object_handle.hpp \
	asio/windows/basic_random_access_handle.hpp \
	asio/windows/basic_stream_handle.hpp \
	asio/windows/object_handle.hpp \
	asio/windows/object_handle_service.hpp \
	asio/windows/overlapped_handle.hpp \
	asio/windows/overlapped_ptr.hpp \
	asio/windows/random_access_handle.hpp \
	asio/windows/random_access_handle_service.hpp \
	asio/windows/stream_handle.hpp \
	asio/windows/stream_handle_service.hpp \
	asio/write_at.hpp \
	asio/write.hpp \
	asio/yield.hpp

MAINTAINERCLEANFILES = \
	$(srcdir)/Makefile.in

all: all-am

.SUFFIXES:
$(srcdir)/Makefile.in: # $(srcdir)/Makefile.am  $(am__configure_deps)
	@for dep in $?; do \
	  case '$(am__configure_deps)' in \
	    *$$dep*) \
	      ( cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh ) \
	        && { if test -f $@; then exit 0; else break; fi; }; \
	      exit 1;; \
	  esac; \
	done; \
	echo ' cd $(top_srcdir) && $(AUTOMAKE) --foreign include/Makefile'; \
	$(am__cd) $(top_srcdir) && \
	  $(AUTOMAKE) --foreign include/Makefile
Makefile: $(srcdir)/Makefile.in $(top_builddir)/config.status
	@case '$?' in \
	  *config.status*) \
	    cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh;; \
	  *) \
	    echo ' cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@ $(am__maybe_remake_depfiles)'; \
	    cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@ $(am__maybe_remake_depfiles);; \
	esac;

$(top_builddir)/config.status: $(top_srcdir)/configure $(CONFIG_STATUS_DEPENDENCIES)
	cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh

$(top_srcdir)/configure: # $(am__configure_deps)
	cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh
$(ACLOCAL_M4): # $(am__aclocal_m4_deps)
	cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh
$(am__aclocal_m4_deps):
install-nobase_includeHEADERS: $(nobase_include_HEADERS)
	@$(NORMAL_INSTALL)
	@list='$(nobase_include_HEADERS)'; test -n "$(includedir)" || list=; \
	if test -n "$$list"; then \
	  echo " $(MKDIR_P) '$(DESTDIR)$(includedir)'"; \
	  $(MKDIR_P) "$(DESTDIR)$(includedir)" || exit 1; \
	fi; \
	$(am__nobase_list) | while read dir files; do \
	  xfiles=; for file in $$files; do \
	    if test -f "$$file"; then xfiles="$$xfiles $$file"; \
	    else xfiles="$$xfiles $(srcdir)/$$file"; fi; done; \
	  test -z "$$xfiles" || { \
	    test "x$$dir" = x. || { \
	      echo " $(MKDIR_P) '$(DESTDIR)$(includedir)/$$dir'"; \
	      $(MKDIR_P) "$(DESTDIR)$(includedir)/$$dir"; }; \
	    echo " $(INSTALL_HEADER) $$xfiles '$(DESTDIR)$(includedir)/$$dir'"; \
	    $(INSTALL_HEADER) $$xfiles "$(DESTDIR)$(includedir)/$$dir" || exit $$?; }; \
	done

uninstall-nobase_includeHEADERS:
	@$(NORMAL_UNINSTALL)
	@list='$(nobase_include_HEADERS)'; test -n "$(includedir)" || list=; \
	$(am__nobase_strip_setup); files=`$(am__nobase_strip)`; \
	dir='$(DESTDIR)$(includedir)'; $(am__uninstall_files_from_dir)

ID: $(am__tagged_files)
	$(am__define_uniq_tagged_files); mkid -fID $$unique
tags: tags-am
TAGS: tags

tags-am: $(TAGS_DEPENDENCIES) $(am__tagged_files)
	set x; \
	here=`pwd`; \
	$(am__define_uniq_tagged_files); \
	shift; \
	if test -z "$(ETAGS_ARGS)$$*$$unique"; then :; else \
	  test -n "$$unique" || unique=$$empty_fix; \
	  if test $$# -gt 0; then \
	    $(ETAGS) $(ETAGSFLAGS) $(AM_ETAGSFLAGS) $(ETAGS_ARGS) \
	      "$$@" $$unique; \
	  else \
	    $(ETAGS) $(ETAGSFLAGS) $(AM_ETAGSFLAGS) $(ETAGS_ARGS) \
	      $$unique; \
	  fi; \
	fi
ctags: ctags-am

CTAGS: ctags
ctags-am: $(TAGS_DEPENDENCIES) $(am__tagged_files)
	$(am__define_uniq_tagged_files); \
	test -z "$(CTAGS_ARGS)$$unique" \
	  || $(CTAGS) $(CTAGSFLAGS) $(AM_CTAGSFLAGS) $(CTAGS_ARGS) \
	     $$unique

GTAGS:
	here=`$(am__cd) $(top_builddir) && pwd` \
	  && $(am__cd) $(top_srcdir) \
	  && gtags -i $(GTAGS_ARGS) "$$here"
cscopelist: cscopelist-am

cscopelist-am: $(am__tagged_files)
	list='$(am__tagged_files)'; \
	case "$(srcdir)" in \
	  [\\/]* | ?:[\\/]*) sdir="$(srcdir)" ;; \
	  *) sdir=$(subdir)/$(srcdir) ;; \
	esac; \
	for i in $$list; do \
	  if test -f "$$i"; then \
	    echo "$(subdir)/$$i"; \
	  else \
	    echo "$$sdir/$$i"; \
	  fi; \
	done >> $(top_builddir)/cscope.files

distclean-tags:
	-rm -f TAGS ID GTAGS GRTAGS GSYMS GPATH tags

distdir: $(BUILT_SOURCES)
	$(MAKE) $(AM_MAKEFLAGS) distdir-am

distdir-am: $(DISTFILES)
	@srcdirstrip=`echo "$(srcdir)" | sed 's/[].[^$$\\*]/\\\\&/g'`; \
	topsrcdirstrip=`echo "$(top_srcdir)" | sed 's/[].[^$$\\*]/\\\\&/g'`; \
	list='$(DISTFILES)'; \
	  dist_files=`for file in $$list; do echo $$file; done | \
	  sed -e "s|^$$srcdirstrip/||;t" \
	      -e "s|^$$topsrcdirstrip/|$(top_builddir)/|;t"`; \
	case $$dist_files in \
	  */*) $(MKDIR_P) `echo "$$dist_files" | \
			   sed '/\//!d;s|^|$(distdir)/|;s,/[^/]*$$,,' | \
			   sort -u` ;; \
	esac; \
	for file in $$dist_files; do \
	  if test -f $$file || test -d $$file; then d=.; else d=$(srcdir); fi; \
	  if test -d $$d/$$file; then \
	    dir=`echo "/$$file" | sed -e 's,/[^/]*$$,,'`; \
	    if test -d "$(distdir)/$$file"; then \
	      find "$(distdir)/$$file" -type d ! -perm -700 -exec chmod u+rwx {} \;; \
	    fi; \
	    if test -d $(srcdir)/$$file && test $$d != $(srcdir); then \
	      cp -fpR $(srcdir)/$$file "$(distdir)$$dir" || exit 1; \
	      find "$(distdir)/$$file" -type d ! -perm -700 -exec chmod u+rwx {} \;; \
	    fi; \
	    cp -fpR $$d/$$file "$(distdir)$$dir" || exit 1; \
	  else \
	    test -f "$(distdir)/$$file" \
	    || cp -p $$d/$$file "$(distdir)/$$file" \
	    || exit 1; \
	  fi; \
	done
check-am: all-am
check: check-am
all-am: Makefile $(HEADERS)
installdirs:
	for dir in "$(DESTDIR)$(includedir)"; do \
	  test -z "$$dir" || $(MKDIR_P) "$$dir"; \
	done
install: install-am
install-exec: install-exec-am
install-data: install-data-am
uninstall: uninstall-am

install-am: all-am
	@$(MAKE) $(AM_MAKEFLAGS) install-exec-am install-data-am

installcheck: installcheck-am
install-strip:
	if test -z '$(STRIP)'; then \
	  $(MAKE) $(AM_MAKEFLAGS) INSTALL_PROGRAM="$(INSTALL_STRIP_PROGRAM)" \
	    install_sh_PROGRAM="$(INSTALL_STRIP_PROGRAM)" INSTALL_STRIP_FLAG=-s \
	      install; \
	else \
	  $(MAKE) $(AM_MAKEFLAGS) INSTALL_PROGRAM="$(INSTALL_STRIP_PROGRAM)" \
	    install_sh_PROGRAM="$(INSTALL_STRIP_PROGRAM)" INSTALL_STRIP_FLAG=-s \
	    "INSTALL_PROGRAM_ENV=STRIPPROG='$(STRIP)'" install; \
	fi
mostlyclean-generic:

clean-generic:

distclean-generic:
	-test -z "$(CONFIG_CLEAN_FILES)" || rm -f $(CONFIG_CLEAN_FILES)
	-test . = "$(srcdir)" || test -z "$(CONFIG_CLEAN_VPATH_FILES)" || rm -f $(CONFIG_CLEAN_VPATH_FILES)

maintainer-clean-generic:
	@echo "This command is intended for maintainers to use"
	@echo "it deletes files that may require special tools to rebuild."
	-test -z "$(MAINTAINERCLEANFILES)" || rm -f $(MAINTAINERCLEANFILES)
clean: clean-am

clean-am: clean-generic mostlyclean-am

distclean: distclean-am
	-rm -f Makefile
distclean-am: clean-am distclean-generic distclean-tags

dvi: dvi-am

dvi-am:

html: html-am

html-am:

info: info-am

info-am:

install-data-am: install-nobase_includeHEADERS

install-dvi: install-dvi-am

install-dvi-am:

install-exec-am:

install-html: install-html-am

install-html-am:

install-info: install-info-am

install-info-am:

install-man:

install-pdf: install-pdf-am

install-pdf-am:

install-ps: install-ps-am

install-ps-am:

installcheck-am:

maintainer-clean: maintainer-clean-am
	-rm -f Makefile
maintainer-clean-am: distclean-am maintainer-clean-generic

mostlyclean: mostlyclean-am

mostlyclean-am: mostlyclean-generic

pdf: pdf-am

pdf-am:

ps: ps-am

ps-am:

uninstall-am: uninstall-nobase_includeHEADERS

.MAKE: install-am install-strip

.PHONY: CTAGS GTAGS TAGS all all-am check check-am clean clean-generic \
	cscopelist-am ctags ctags-am distclean distclean-generic \
	distclean-tags distdir dvi dvi-am html html-am info info-am \
	install install-am install-data install-data-am install-dvi \
	install-dvi-am install-exec install-exec-am install-html \
	install-html-am install-info install-info-am install-man \
	install-nobase_includeHEADERS install-pdf install-pdf-am \
	install-ps install-ps-am install-strip installcheck \
	installcheck-am installdirs maintainer-clean \
	maintainer-clean-generic mostlyclean mostlyclean-generic pdf \
	pdf-am ps ps-am tags tags-am uninstall uninstall-am \
	uninstall-nobase_includeHEADERS

.PRECIOUS: Makefile


# Tell versions [3.59,3.63) of GNU make to not export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
