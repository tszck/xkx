// Room: /d/chengdu/zongzidian.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit ROOM;

void create()
{
	set("short", "阿林糉子店");
	set("long", @LONG
這是一家和嘉興“六芳齋”聯營的糉子店。店主人張禽林據說是湖
北邵縣的一個書生。因爲愛上當地青樓的一個歌妓霍琳琳，所以棄書從
商，發誓要賺錢爲愛人贖身。但是他並不是做生意的料，開店後生意一
直不好，因此在他臉上幾乎看不到笑容。
LONG	);
	set("exits", ([		
		"west" : __DIR__"xiaojie1",
	]));
	set("objects", ([
		__DIR__"npc/zhangqinlin" : 1,
	]));
	set("coor/x", -8010);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

