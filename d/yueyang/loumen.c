// Room: /d/yueyang/loumen.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "嶽陽樓門");
	set("long", @LONG
這裏是嶽陽樓的大門，門上是一幅黑底藍字對聯“洞庭天下水，嶽
陽天下樓”。嶽陽樓建在嶽陽城樓上，建築精巧雄偉，與洪都滕王閣、
武昌黃鶴樓並稱江南三大名樓，
LONG );
	set("outdoors", "yueyang");
	set("no_clean_up", 0);
	set("exits", ([
		"west"      : __DIR__"huaiputing",
		"southdown" : __DIR__"ximen",
	]));
	set("coor/x", -1430);
	set("coor/y", -2260);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
