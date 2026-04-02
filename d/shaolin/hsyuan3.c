// Room: /d/shaolin/hsyuan3.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "和尚院三部");
	set("long", @LONG
這裏是僧眾們飲食起居的地方。靠牆一溜擺着幾張木牀，牀
上鋪的是篾席。牀頭疊着牀薄被，冬天想必很冷，僧侶們全靠扎
實的內功根基禦寒。地上整齊的放着幾個蒲團和木魚。
LONG );
	set("sleep_room",1);
	set("exits", ([
		"east" : __DIR__"zhulin3",
		"south" : __DIR__"hsyuan2",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/hui-se" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", 10);
	set("coor/y", 910);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}