// Room: /d/luoyang/hulaoguan.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "虎牢關");
	set("long",  @LONG
虎牢關又稱汜水關、成皋關，因西周穆王在此牢虎而得名。歷朝歷
代，無不在此設防。虎牢南連嵩嶽，北瀕黃河，山嶺交錯，自成天險。
大有一夫當關，萬夫莫開之勢，為歷代兵家必爭之地，尤以三英戰呂布
更使其名聲大震。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"west" : __DIR__"road2",
		"east" : __DIR__"road0",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		"/d/city/npc/bing" : 2,
	]));
	set("outdoors", "luoyang");
	set("coor/x", -180);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

