// Room: /d/heimuya/road4.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
        set("short", "黃土路");
	set("long", @LONG
你走在一條黃土路上。這裏是山西地界，往東就進入河北了。現在
這裏不是太平時節，還是快點走吧。
LONG );
        set("outdoors", "heimuya");
        set("exits", ([
                "northeast" : __DIR__"road1",
                "southwest" : __DIR__"dukou1",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3030);
	set("coor/y", 4020);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}