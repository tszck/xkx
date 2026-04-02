// Room: /d/henshan/jigaoming.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "極高明臺");
        set("long", @LONG
這裏是福嚴寺最高處。唐鄴侯李泌手書 "極高明" 三個大字於此，
意即佛相極高 (高無見頂相) ，佛光極明 (明不借他光) ，佛是至高無
上的，故曰極高明臺。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "northdown"  : __DIR__"sansheng",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -340);
	set("coor/y", -1080);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}
