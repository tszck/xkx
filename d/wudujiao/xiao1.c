// Room: /d/wudujiao/xiao1.c

inherit ROOM;

void create()
{
        set("short", "江邊小路");
        set("long", @LONG
這裏是桃花江邊的一條泥土小路，一旁就是清澈的江水。夾岸
連綿不斷的桃花燦若雲霞，暗香襲人，引來許多蜜蜂在花樹間飛舞。
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "south" : __DIR__"xiao2",
                "north" : __DIR__"jiang2",
        ]));

	set("coor/x", -45000);
	set("coor/y", -81020);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}