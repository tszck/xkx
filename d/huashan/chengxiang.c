 // chengxiang.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "沉香劈山處");
	set("long", @LONG
傳説華山三聖母愛上了一個叫劉彥昌的書生，結為夫婦，其兄二郎
神反對他們結合，將她壓在華山下，她的兒子沉香長大後用斧子劈開華
山，救出了母親。旁邊有一塊中間裂開的大石，象用斧子劈開的一般，
叫做斧劈石。傳説就是沉香劈山救母的地方。
LONG );
	set("exits", ([ /* sizeof() == 3 */
		"westup"   : __DIR__"lianhua",
		"eastdown" : __DIR__"lianpath2",
	]));

	set("no_clean_up", 0);
	set("outdoors", "huashan" );

	set("coor/x", -900);
	set("coor/y", 180);
	set("coor/z", 130);
	setup();
	replace_program(ROOM);
}
