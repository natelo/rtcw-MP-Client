# FIXME: add targets for ui/cgame/game + debug targets
# FIXME: basically what cons used - needs tuning
CFLAGSREL := \
	-m32 -pipe -march=pentium4 -O3 -fomit-frame-pointer -ffast-math \
	-falign-loops=2 -falign-jumps=2 -falign-functions=2 \
	-fno-strict-aliasing -fstrength-reduce -DNDEBUG $(CFLAGSEXT)

%.o : %.nasm
	$(NASM) -f elf -o $@ $<
%.o : %.s
	$(CC) $(CFLAGS) -DELF -x assembler-with-cpp -c -o $@ $<
%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# ../splines/q_shared.cpp seems unneeded and conflicts when compiling 
# all files at once
SPLINEOBJS := \
	../splines/math_angles.o ../splines/math_matrix.o \
	../splines/math_quaternion.o ../splines/math_vector.o \
	../splines/q_parse.o ../splines/splines.o ../splines/util_str.o
BOTLIBOBJS := \
	../botlib/be_aas_bspq3.o ../botlib/be_aas_cluster.o \
	../botlib/be_aas_debug.o ../botlib/be_aas_entity.o \
	../botlib/be_aas_file.o ../botlib/be_aas_main.o \
	../botlib/be_aas_move.o ../botlib/be_aas_optimize.o \
	../botlib/be_aas_reach.o ../botlib/be_aas_route.o \
	../botlib/be_aas_routealt.o ../botlib/be_aas_routetable.o \
	../botlib/be_aas_sample.o ../botlib/be_ai_char.o \
	../botlib/be_ai_chat.o ../botlib/be_ai_gen.o \
	../botlib/be_ai_goal.o ../botlib/be_ai_move.o \
	../botlib/be_ai_weap.o ../botlib/be_ai_weight.o ../botlib/be_ea.o \
	../botlib/be_interface.o ../botlib/l_crc.o ../botlib/l_libvar.o \
	../botlib/l_log.o ../botlib/l_memory.o ../botlib/l_precomp.o \
	../botlib/l_script.o ../botlib/l_struct.o
JPGLIBOBJS := \
	../jpeg-6/jcapimin.o ../jpeg-6/jchuff.o ../jpeg-6/jcinit.o \
	../jpeg-6/jccoefct.o ../jpeg-6/jccolor.o ../jpeg-6/jfdctflt.o \
	../jpeg-6/jcdctmgr.o ../jpeg-6/jcphuff.o ../jpeg-6/jcmainct.o \
	../jpeg-6/jcmarker.o ../jpeg-6/jcmaster.o ../jpeg-6/jcomapi.o \
	../jpeg-6/jcparam.o ../jpeg-6/jcprepct.o ../jpeg-6/jcsample.o \
	../jpeg-6/jdapimin.o ../jpeg-6/jdapistd.o ../jpeg-6/jdatasrc.o \
	../jpeg-6/jdcoefct.o ../jpeg-6/jdcolor.o ../jpeg-6/jddctmgr.o \
	../jpeg-6/jdhuff.o ../jpeg-6/jdinput.o ../jpeg-6/jdmainct.o \
	../jpeg-6/jdmarker.o ../jpeg-6/jdmaster.o ../jpeg-6/jdpostct.o \
	../jpeg-6/jdsample.o ../jpeg-6/jdtrans.o ../jpeg-6/jerror.o \
	../jpeg-6/jidctflt.o ../jpeg-6/jmemmgr.o ../jpeg-6/jmemnobs.o \
	../jpeg-6/jutils.o
ASMOBJS := \
	../unix/ftol.o ../unix/snapvector.o
INLINEOBJS := \
	../unix/matha.o ../unix/snd_mixa.o
RENDEROBJS := \
	../renderer/tr_animation.o ../renderer/tr_backend.o \
	../renderer/tr_bsp.o ../renderer/tr_cmds.o \
	../renderer/tr_cmesh.o ../renderer/tr_curve.o \
	../renderer/tr_flares.o ../renderer/tr_font.o \
	../renderer/tr_image.o ../renderer/tr_init.o \
	../renderer/tr_light.o ../renderer/tr_main.o \
	../renderer/tr_marks.o ../renderer/tr_mesh.o \
	../renderer/tr_model.o ../renderer/tr_noise.o \
	../renderer/tr_scene.o ../renderer/tr_shade.o \
	../renderer/tr_shade_calc.o ../renderer/tr_shader.o \
	../renderer/tr_shadows.o ../renderer/tr_sky.o \
	../renderer/tr_surface.o ../renderer/tr_world.o \
        ../renderer/tr_bloom.o
CLIENTOBJS := \
	../client/cl_cgame.o ../client/cl_cin.o ../client/cl_console.o \
	../client/cl_input.o ../client/cl_keys.o ../client/cl_main.o \
	../client/cl_net_chan.o ../client/cl_parse.o ../client/cl_scrn.o \
	../client/cl_ui.o ../client/cl_control.o ../client/cl_irc.o \
        ../qcommon/dl_main_curl.o ../client/cl_GetHDDSerial.o  
COMMONOBJS := \
	../qcommon/cm_load.o ../qcommon/cm_patch.o ../qcommon/cm_polylib.o \
	../qcommon/cm_test.o ../qcommon/cm_trace.o ../qcommon/cmd.o \
	../qcommon/common.o ../qcommon/cvar.o ../qcommon/files.o \
	../qcommon/md4.o ../qcommon/msg.o ../qcommon/net_chan.o \
	../qcommon/huffman.o ../qcommon/unzip.o ../qcommon/md5.o  \
	../qcommon/htable.o
SOUNDOBJS := \
	../client/snd_adpcm.o ../client/snd_dma.o ../client/snd_mem.o \
	../client/snd_mix.o ../client/snd_wavelet.o
SERVEROBJS := \
	../server/sv_bot.o ../server/sv_ccmds.o ../server/sv_client.o \
	../server/sv_game.o ../server/sv_init.o ../server/sv_main.o \
	../server/sv_net_chan.o ../server/sv_snapshot.o \
	../server/sv_world.o ../server/sv_control.o ../qcommon/http.o ../qcommon/http_main.o
# ../qcommon/vm_x86.c is not used and not nice to port to mingw
VMOBJS := \
	../qcommon/vm.o ../qcommon/vm_interpreted.o
SHAREDOBJS := \
	../game/q_shared.o ../game/q_math.o
DEDOBJS := \
	../null/null_client.o ../null/null_input.o ../null/null_snddma.o
UNIXCLIENTOBJS := \
	../unix/linux_qgl.o ../unix/linux_glimp.o ../unix/linux_joystick.o \
	../unix/linux_snd.o
UNIXOBJS := \
	../unix/linux_common.o ../unix/unix_main.o ../qcommon/net_ip.o \
	../unix/unix_shared.o ../unix/linux_signals.o
WINCLIENTOBJS := \
	../win32/win_gamma.o ../win32/win_glimp.o ../win32/win_input.o \
	../win32/win_qgl.o ../win32/win_snd.o
WINOBJS := \
	../win32/win_main.o ../win32/win_net.o ../win32/win_syscon.o \
	../win32/win_wndproc.o ../win32/win_shared.o

#####################################################################

CLOBJS := \
	$(SPLINEOBJS) $(BOTLIBOBJS) $(JPGLIBOBJS) $(ASMOBJS) $(INLINEOBJS) \
	$(RENDEROBJS) $(CLIENTOBJS) $(COMMONOBJS) $(SOUNDOBJS) $(SERVEROBJS) \
	$(UNIXOBJS) $(UNIXCLIENTOBJS) $(VMOBJS) $(SHAREDOBJS)
CLWINOBJS := \
	$(SPLINEOBJS) $(BOTLIBOBJS) $(JPGLIBOBJS) $(RENDEROBJS) $(CLIENTOBJS) \
	$(COMMONOBJS) $(SOUNDOBJS) $(SERVEROBJS) $(WINOBJS) $(WINCLIENTOBJS) \
	$(VMOBJS) $(SHAREDOBJS)
SVOBJS := \
	$(BOTLIBOBJS) $(ASMOBJS) $(SERVEROBJS) $(COMMONOBJS) $(DEDOBJS) \
	$(VMOBJS) $(UNIXOBJS) $(SHAREDOBJS)
SVWINOBJS := \
	$(BOTLIBOBJS) $(SERVEROBJS) $(COMMONOBJS) $(DEDOBJS) $(VMOBJS) \
	$(WINOBJS) $(SHAREDOBJS)

#####################################################################

client: CC := gcc
client: NASM := nasm
client: CFLAGS := $(CFLAGSREL) -DBOTLIB -DDLL_ONLY
client: CPPFLAGS := $(CFLAGS)     
client: LDFLAGS := \
	-m32 -lX11 -lXext -lXxf86dga -lXxf86vm -ldl -lm -lstdc++ -lcurl
client: $(CLOBJS)
	$(CC) -o WolfMP.x86 $(CLOBJS) $(LDFLAGS)
	strip -s WolfMP.x86
client-clean:
	rm $(CLOBJS) 2> /dev/null ; exit 0
	
#####################################################################

# FIXME: this needs a symlink from include/gl to include/GL since win32
# paths arent case sensitive - maybe fix in renderer/qgl.h
# FIXME: jmorecfg.h defines INT32 and conflicts with mingws basetsd.h
# included by windows.h - adjusted basetsd.h for now but should be
# really fixed in jmorecfg.h (libjpeg update?)
# FIXME: is uname -m suitable for CPUSTRING?
# FIXME: had to undef __i386__ to avoid msvc style inline asm - probably
# not the cleanest solution
# NOTE: dinput.h and dsound.h missing from mingw but available
# from dx80_mgw.zip at http://alleg.sourceforge.net/wip.html
client-w32: CC := i586-mingw32msvc-gcc
client-w32: CXX := i586-mingw32msvc-g++
client-w32: CFLAGS := \
	$(CFLAGSREL) -DBOTLIB -DDLL_ONLY -DCPUSTRING=\"`uname -m`\" \
	-U__i386__ -DSPI_SCREENSAVERRUNNING=SPI_SETSCREENSAVERRUNNING \
	-DCURL_STATICLIB
client-w32: CPPFLAGS := $(CFLAGS)
client-w32: LDFLAGS := \
	-m32 -lwinmm -lopengl32 -lgdi32 -lws2_32 -static-libgcc `$(CXX) \
	-print-file-name=libstdc++.a`
client-w32: $(CLWINOBJS)
	$(CXX) -o WolfMP.exe $(CLWINOBJS) $(LDFLAGS)
	strip -s WolfMP.exe
client-w32-clean:
	rm $(CLWINOBJS) 2> /dev/null ; exit 0

#####################################################################

server: CC := gcc
server: NASM := nasm
server: CFLAGS := \
	$(CFLAGSREL) -DBOTLIB -DDEDICATED -DC_ONLY -DDLL_ONLY
server: LDFLAGS := -m32 -ldl -lm -Lcurl-7.29.0\lib\libcurld -lcurl
server: $(SVOBJS)
	$(CC) -o WolfDED.x86 $(SVOBJS) $(LDFLAGS)
	strip -s WolfDED.x86
server-clean:
	rm $(SVOBJS) 2> /dev/null ; exit 0
	
#####################################################################

# FIXME: is uname -m suitable for CPUSTRING?
# FIXME: had to undef __i386__ to avoid msvc style inline asm - probably
# not the cleanest solution
server-w32: CC := i586-mingw32msvc-gcc
server-w32: CFLAGS := \
	$(CFLAGSREL) -DBOTLIB -DDEDICATED -DC_ONLY -DDLL_ONLY \
	-DCPUSTRING=\"`uname -m`\" -U__i386__ \
	-DSPI_SCREENSAVERRUNNING=SPI_SETSCREENSAVERRUNNING
server-w32: LDFLAGS := -m32 -lwinmm -lgdi32 -lws2_32 -Lcurl-7.29.0\lib\libcurld -lcurl
server-w32: $(SVWINOBJS)
	$(CC) -o WolfDED.exe $(SVWINOBJS) $(LDFLAGS)
	strip -s WolfDED.exe
server-w32-clean:
	rm $(SVWINOBJS) 2> /dev/null ; exit 0

#####################################################################

CURLCONF := \
	--enable-shared=no --enable-static=yes --disable-rtsp \
	--disable-ldap --disable-dict --disable-file --disable-gopher \
	--disable-imap --disable-pop3 --disable-smtp --disable-telnet \
	--disable-tftp --without-ca-bundle --without-libidn \
	--without-ca-path --without-nss --without-polarssl \
	--without-gnutls --without-zlib --without-ssl --with-gnu-ld \
	--disable-cookies --disable-tls-srp --disable-ntlm-wb \
	--disable-sspi --disable-verbose  --disable-threaded-resolver \
	--disable-nonblocking --disable-manual

curl: 
	cd ../curl-7.29.0 && sh configure $(CURLCONF)
	cd ../curl-7.29.0 && make
	mv ../curl-7.29.0/lib/.libs/libcurl.a ../curl-7.29.0/lib/.libs/libcurl_linux.a
	cp -R ../curl-7.29.0/include/curl ../curl-7.29.0/include/curl_linux

curl-w32:
	cd ../curl-7.29.0 && CC=i586-mingw32msvc-gcc RANLIB=i586-mingw32msvc-ranlib \
	CPPFLAGS=-DCURL_STATICLIB sh configure $(CURLCONF) --host=mingw32
	cd ../curl-7.29.0 && make
	mv ../curl-7.29.0/lib/.libs/libcurl.a ../curl-7.29.0/lib/.libs/libcurl_w32.a
	cp -R ../curl-7.29.0/include/curl ../curl-7.29.0/include/curl_w32

curl-clean:
	cd ../curl && make clean
	rm -rf ../curl/include/curl_linux
	rm -rf ../curl/include/curl_w32

#####################################################################

clean:
	make client-clean
	make client-w32-clean
	make server-clean
	make server-w32-clean
	
all:
	make clean
	make client
	make client-clean
	make server
	make server-clean
	make client-w32
	make client-w32-clean
	make server-w32
	make server-w32-clean

# FIXME: could be more clever
test:
	if [ "$$RTCW_TESTBASE" = "" ]; then \
	RTCW_TESTBASE=~/Software/rtcw ; fi ; \
	cp WolfMP.x86 "$$RTCW_TESTBASE" ; \
	cp WolfMP.exe "$$RTCW_TESTBASE" ; \
	cp WolfDED.x86 "$$RTCW_TESTBASE" ; \
	cp WolfDED.exe "$$RTCW_TESTBASE"
