// /d/beihai/baita.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "瓊島白塔");
	set("long", @LONG
百塔爲以瓊華島爲主體組成的四面景觀的中心。位於北海瓊華島之
巔。白塔上爲喇嘛塔，下爲高大的磚石臺基，塔座爲折角式須彌座，其
上承託覆鉢式塔身，正面中有壺門式眼光門，門內刻有藏文咒語。塔身
上部爲細長的十三天，上爲兩層銅質傘蓋，邊緣懸銅鐘十四個，最上爲
鎏金火焰寶珠塔剎。
LONG
	);
	set("exits", ([
		"northdown" : __DIR__"yilan",
		"southdown" : __DIR__"yongansi",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);
	set("coor/x", -190);
	set("coor/y", 4090);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
