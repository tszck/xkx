// Room: /d/nanshaolin/sengshe5.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "西僧舍");
	set("long", @LONG
這裏是僧衆們飲食起居的地方。靠牆一溜擺着幾張木牀，牀上鋪的
是篾席。牀頭疊着牀薄被，冬天想必很冷，僧侶們全靠紮實的內功根基
禦寒。地上整齊的放着幾個蒲團和木魚。
LONG );
	set("sleep_room",1);
        set("no_fight", 1);
	set("exits", ([
		"south" : __DIR__"sengshe4",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1800);
	set("coor/y", -6220);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}

