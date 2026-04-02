//Room: jinding.c 金頂
//Date: Sep 22 1997

inherit ROOM;

void create()
{
	set("short","金頂");
	set("long",@LONG
你感到寒意陣陣襲來，原來你已到了武當山的主峯天柱峯的絕頂。
前面的金殿由銅鑄成，鍍以黃金，每當旭日臨空，整個殿宇金光閃閃，
故名金頂。天柱峯高高獨立於羣峯之上，東西壁立二山，名叫蠟燭峯，
中壁立一山似香爐，名香爐峯，萬山千壑，隱隱下伏。
LONG);
	set("exits",([ /* sizeof() == 1 */
		"west"      : __DIR__"shierliantai",
		"south"     : __DIR__"zijincheng",
		"northdown" : __DIR__"santiangate",
	]));
	set("objects",([ /* sizeof() == 1 */
	    CLASS_D("wudang")+"/chongxu" : 1,
	]));
	set("outdoors", "wudang");
	set("no_clean_up", 0);
	set("coor/x", -2030);
	set("coor/y", -1040);
	set("coor/z", 180);
	setup();
	replace_program(ROOM);
}
