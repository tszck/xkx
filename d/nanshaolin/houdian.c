// Room: /d/nanshaolin/houdian.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
void create()
{
	set("short", "後殿");
	set("long", @LONG
後殿規模不大。兩邊都是水磨石壁，鏤刻着佛門各位先賢大德的肖
像及慧心妙語，正中有一口大水缸(gang)，以濟寺內僧人練武口渴及日
常飲用之需。每日都有專職僧侶從寺前佛心井中擔水來此。
LONG 
);
	set("exits", ([
		"west"  : __DIR__ "hguangc4",
		"east"  : __DIR__ "hguangc5",
		"north" : __DIR__ "taijie",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/fangjie" : 1,
		__DIR__"npc/zjseng" : 1,
	]));
	set("item_desc", ([
		"gang" : "這是一口銅製的大缸，足可以盛下幾百桶水。\n",
	]));
	set("resource/water",1); 
	set("coor/x", 1820);
	set("coor/y", -6180);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}	   
