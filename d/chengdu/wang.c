// Room: /d/chengdu/wang.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "梁王府");
	set("long", @LONG
這裏是梁王府的大門，兩邊是兩個威武的石獅子，高高的臺階，中
間是正門，兩邊是邊門，幾個王府衞士整齊的守衞在兩旁，門口顯得很
安靜，普通百姓是不許逗留的。
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"east" : __DIR__"nanjie1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8060);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

