// Room: zhugeliang.c
// Date: Feb.14 1998 by Java

inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "諸葛亮殿");
	set("long", @LONG
這裏是武侯祠的正殿諸葛亮殿。武侯羽扇綸巾一如生前。兩邊諸葛瞻
和諸葛尚父子塑像也栩栩如生。掛在殿門兩壁的，由詩聖杜甫筆下流露的
千古名聯：“三顧頻頻天下事，兩朝開濟老臣心。”道盡了這個千古風範
的一生心事。
LONG );
	set("exits", ([
		"southdown" : __DIR__"liubeidian",
	]));
	set("objects", ([
		__DIR__"npc/youke" : random(3),
	]));
	set("coor/x", -8070);
	set("coor/y", -3000);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
