// Room: majiangting.c
// Last Modified by winder on Aug. 18 2002

inherit ROOM;

void create()
{
	set("short", "麻將廳");
	set("long", @LONG
麻將廳裏顯得十分安靜，偶爾從房間裏傳出洗牌的聲音。大家都壓
低了嗓子説話，似乎每圈輸贏都關係着什麼似的。東西兩間是美女陪伴
的練兵場，玩家想自己對決，就到南間去吧。
LONG );
	set("no_fight", "1");
	set("no_beg", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("no_clean_up", 0);
	set("exits", ([
		"west"  : __DIR__"majiangroom1",
		"east"  : __DIR__"majiangroom2",
		"north" : __DIR__"zoulang1",
		"south" : __DIR__"majiangroom",
	]));

	set("coor/x", 20);
	set("coor/y", 9);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
