// Room: /city/wumiao2.c
// YZC 1995/12/04 

#include <room.h>

#define BOARD_TOC "/doc/board/toc"
#define BOARD_DIR "/doc/board/"
inherit ROOM;
string look_shu();

void create()
{
	set("short", "武廟二樓");
	set("long", @LONG
這裏是嶽王廟的二樓，這裏供的是嶽飛的長子嶽雲和義子張憲，兩
尊塑像金盔銀鎧，英氣勃勃。樓上是本泥潭的名人堂。
    進門口有一個小案桌，上面壘着一堆書 (shu)，記錄了俠客行一百
老玩家們寫的這個泥潭過去的一些故事。你可以依號閱讀(yuedu)。
LONG );

	set("no_fight", "1");
	set("no_steal", "1");
	set("no_beg", "1");
	set("no_sleep_room", "1");
	set("no_clean_up", 0);

        set("item_desc", ([
		"shu" : (: look_shu :),
	]));
        set("objects", ([
		"/clone/topten/topten": 1,
	]));
	set("exits", ([
		"down" : __DIR__"wumiao",
		"up"   : __DIR__"mingren",
	]));
	set("coor/x", 0);
	set("coor/y", 0);
	set("coor/z", 10);
	setup();
}

void init()
{
        add_action("do_read", "yuedu");
}

string look_shu()
{
        this_player()->start_more(read_file(BOARD_TOC));
        return "\n";
}

int do_read(string arg)
{
        object me=this_player();
        if (arg == "" || file_size(BOARD_DIR + arg) <= 0)
                return notify_fail("好象沒有這條公告耶。\n");

        log_file("LIBRARY", sprintf("%s read %s.\n", me->query("name"), arg));
        me->start_more(read_file(BOARD_DIR + arg));
        return 1;
}