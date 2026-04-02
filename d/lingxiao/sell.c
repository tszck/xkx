// Room: /d/lingxiao/sell.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "水晶當");
	set("long", @LONG 
這裏是凌霄城的大當鋪--水晶當。它名叫水晶當，不僅是因為它的
招牌是水晶所制，更重要的是它的信譽鼎然，在凌霄城中名聲向來不錯。
所以人稱“水晶當”。老闆陳朝奉，正坐在櫃枱後，笑嘻嘻地同客人討
價還價。
LONG );
	set("no_fight", 1);
	set("no_steal", 1);
	set("no_beg",1);
	set("item_desc", ([
		"paizi" : "水晶招牌，童叟無欺\n
sell        賣 
buy         買
redeem      贖
value       估價
",
	]));
	set("objects", ([
		__DIR__"npc/laoban" : 1,
		__DIR__"npc/dizi" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"iceroad1",
	]));
	set("coor/x", -30990);
	set("coor/y", -8920);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

