//Edited by fandog, 02/15/2000

inherit ROOM;

void create()
{
	set("short", "蟲二茶館");
	set("long", @LONG
一走進來，就聞到一股茶香沁入心脾，你不禁精神爲之一爽。幾張
八仙桌一字排開，坐滿了客人，或高聲談笑，或交頭接耳。你要打聽江
湖掌故和謠言，這裏是個好所在。這家茶館的主人是個風雅之士，起名
“蟲二”要的是“風月無邊”。
LONG );
	set("resource/water", 1);
	set("exits", ([
		"west" : __DIR__"dongjie2",
	]));
	set("objects", ([
		__DIR__"npc/chongyi" : 1,
	]));
	set("coor/x", -1460);
	set("coor/y", -2030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}