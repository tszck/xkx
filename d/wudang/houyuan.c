// houyuan.c 後院
// by Xiang

inherit ROOM;

void create()
{
        set("short", "後院");
        set("long", @LONG
這裏是後院，北面是三清殿，南面是一個圓形的門洞，有一條小路
通往後山。
LONG );
        set("exits", ([
                "south" : __DIR__"xiaolu1",
                "north" : __DIR__"sanqingdian",
        ]));
        set("objects", ([
                CLASS_D("wudang") + "/yu" : 1
        ]));
//        set("no_clean_up", 0);
	set("coor/x", -2050);
	set("coor/y", -930);
	set("coor/z", 90);
	setup();
        replace_program(ROOM);
}
