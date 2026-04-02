// /guanwai/tianchi1.c

inherit ROOM;

void create()
{
	set("short", "長白天池");
	set("long", @LONG
“天池在長白山巔中心點，羣峯環抱，離地高約二十里，故名天池
。”天池碧波盈盈，清澈湛藍。湖周圍峭壁百丈，峯影雲影倒映其中，
湖光山色、嵐影雲天十分誘人。湖岸周遭芳草茵茵，百花吐豔。古人詩
雲：“周迥八十里，峭壁立池邊。水滿疑天池，雲低別有天。江山宜漫
畫，鹿逐結前緣。予卜攜書隱，遨遊慰晚年。”
LONG );
	set("exits", ([
		"south"    : __DIR__"tianchi2",
		"northup"  : __DIR__"longmen",
		"westup"   : __DIR__"baiyun",
		"eastup"   : __DIR__"huagai",
	]));
	set("no_clean_up", 0);
	set("outdoors", "changbai");
	set("coor/x", 6190);
	set("coor/y", 5170);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}