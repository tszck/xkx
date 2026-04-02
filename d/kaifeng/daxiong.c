// /kaifeng/daxiong.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "大雄寶殿");
	set("long", @LONG
經過九級石頭臺階，正面就是佛祖神像，兩邊普賢和文殊。高大的
佛像幾乎捱到了屋頂，令人凌然生威。正對着門的地方擺着幾張供桌，
上面是時鮮的瓜果。供桌兩邊的大蜡燭比人還高。兩邊是十八羅漢。
LONG);
	set("objects", ([
		__DIR__"npc/obj/rulaixiang" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"zhongyuan",
		"north" : __DIR__"houyuan",
	]));

	setup();
	replace_program(ROOM);
}
