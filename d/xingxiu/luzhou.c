// Room: /d/xingxiu/luzhou.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "沙漠綠洲");
	set("long", @LONG
在沙漠的盡頭出現了一個綠洲。灌木叢中有一眼坎兒井。井臺上有
一個木杯專供口渴的行人喝水。井邊是一塊瓜地。
LONG );
	set("resource/water", 1);
	set("outdoors", "xiyu");
	set("exits", ([
		"northeast" : __DIR__"shanjiao",
		"southwest" : __DIR__"nanjiang3",
		"south"	    : "/d/npc/m_weapon/lianbianshi",
	]));

	set("objects", ([
	    __DIR__"npc/obj/donkey" : 1,
	    __DIR__"npc/obj/hamigua" : 2,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -41000);
	set("coor/y", 9000);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_drink", "drink");
}
int do_drink(string arg)
{
	int current_water;
	int max_water;
	object me;

	me = this_player();
	current_water = me->query("water");
	max_water = me->query("str")*10 + 100;
	if (current_water<max_water)
	{
	    me->set("water", current_water+30);
	    message("vision", me->name()+"趴在坎兒井的井臺上用木杯舀了一杯水喝。\n", environment(me), ({me}) );
	    write("你喝了一口井中從天山上流淌下來的雪水，簡直比蜜還甜。\n");
	}
	else write("逮着不要錢的水就這麼喝，至於嗎？\n");

	return 1;
}

