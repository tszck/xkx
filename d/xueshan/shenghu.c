//      shenghu.c 聖湖

inherit ROOM;

void create()
{
        set("short","聖湖");
        set("long",@LONG
眼前就是著名的聖湖，碧藍的湖面倒影着藍天和白雲，浩淼的水面
讓人心曠神怡。遠處金碧輝煌的雪山寺清晰可見，再遠處是幾座延綿的
大雪山，其中最高大的是神山，相傳山中有神仙居住。雪山中融化的雪
水都匯入湖中。
LONG );
        set("resource/water",1);
	set("outdoors", "xueshan");
        set("exits",([
                "south" : __DIR__"tulu3",
                "east"  : __DIR__"hubian1",
		"west"  : "/d/npc/m_weapon/liangunshi",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -30020);
	set("coor/y", -8010);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
