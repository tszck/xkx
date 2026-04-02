// siguoya.c
// Dec.11 1997 by Venus

inherit ROOM;
void create()
{
	set("short", "思過崖");
	set("long", @LONG
這是華山的思過崖。危崖上有個山洞，是華山派歷代弟子犯規後囚
禁受罰之所。崖上光禿禿的寸草不生，更無一株樹木。這危崖自來自來
相傳是玉女髮釵上的一顆珍珠，當年華山派的祖師以此危崖爲懲罰弟子
之所，主要是此處無草無木，無蟲無鳥，受罰的弟子在面壁思過之時，
不致爲外物所擾，心有旁騖。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"enter"     : __DIR__"sgyhole1",
		"northdown" : __DIR__"yunupath2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huashan" );
	set("coor/x", -860);
	set("coor/y", 160);
	set("coor/z", 130);
	setup();
}
 
void init()
{
	object me = this_player();
	if (me->query_temp("xunshan")) me->set_temp("xunshan/siguo", 1);
	return;
}
