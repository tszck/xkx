// /guanwai/tianchi2.c

inherit ROOM;

void create()
{
	set("short", "長白天池");
	set("long", @LONG
天池十天九霧，雲蒸霧繞，變幻無窮。瞬息萬變的霧靄風雨，使天
池時而清亮如藍天明鏡，時而縹緲如輕瑩薄紗，時而騰躍如大海波濤，
景色大觀令人神往。
LONG );
	set("exits", ([
		"north"    : __DIR__"tianchi1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "changbai");
	set("coor/x", 6190);
	set("coor/y", 5160);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}