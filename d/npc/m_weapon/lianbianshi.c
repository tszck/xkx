// ROOM lianbianshi.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;
void create()
{
	set("short", "造鞭潭");
	set("long", @LONG
這裏是玄兵古洞的打造鋼鞭的地方。處在荒蕪人煙的戈壁灘上。居
然能有這樣一泓漂亮的潭水，真是讓人不得不讚嘆大自然的鬼斧神工。
潭邊婷婷站者一位妙齡的少女，手中把玩着一把看似極是鋒利的匕首，
呆呆的看着深邃的潭水出神。
LONG );
	set("exits", ([
		"north" : "/d/xingxiu/nanjiang3",
	]));
	set("objects", ([
		__DIR__"npc/shibian" :1,
	]));
	set("coor/x", -41010);
	set("coor/y", 8950);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
