// Room: /city/chanzhisi.c

inherit ROOM;

void create()
{
	set("short", "禪智寺");
	set("long", @LONG
這是揚州最有名的一間寺廟，廟中香火極盛。又得當地官府權貴欣
賞，寺廟修得氣勢不凡，門口的牌樓顯得十分地高大，上面的燙金匾牌
一新如洗。兩邊黃牆黑桅，也看得出是年年修繕。
LONG );
	set("exits", ([
		"north"  : __DIR__"chanzhidadian",
		"south"  : __DIR__"chanzhimenqian",
	]));
	set("objects", ([
		__DIR__"npc/kanmenseng": 1,
	]));
	set("coor/x", -20);
	set("coor/y", -9);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}