// Room: paixiting.c
// Last Modified by winder on Aug. 18 2002

inherit ROOM;

void create()
{
	set("short", "牌戲廳");
	set("long", @LONG
這裏是牌戲廳。周圍的各個房間的門都虛掩着，裏面煙霧繚繞。看
來正在上癮。你輕輕貼近房門，就可以清晰地聽到紙牌砸在桌面上的聲
音，夾雜着偶爾響起的起鬨聲。
LONG );
	set("no_fight", "1");
	set("no_beg", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("no_clean_up", 0);
	set("exits", ([
		"west"  : __DIR__"yapairoom",
		"east"  : __DIR__"pai9room",
		"south" : __DIR__"zoulang1",
		"north" : __DIR__"gongzhuroom",
	]));

	set("coor/x", 20);
	set("coor/y", 9);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
