// Room: /d/lingxiao/huajing.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","花徑");
	set("long",@LONG 
這是一條種滿了各色梅花的花徑。在小徑兩邊，梅花飄香，梅萼生
寒。悠然而賞鑑，梅枝蜿蜒，梅乾崎嶇，古樸飄逸，兼而有之。梅樹枝
幹以枯殘醜拙為貴，梅花梅萼以繁密濃聚為尚，此處之景，可謂得矣。
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"east" : __DIR__"qianyuan",
		"up"   : __DIR__"feihua",  
	]));
	set("objects", ([
	       __DIR__"npc/xuehe" : 1,
	       __DIR__"obj/mei" : 1,
	]));
	set("coor/x", -31010);
	set("coor/y", -8880);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

