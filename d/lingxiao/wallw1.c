// Room: /d/lingxiao/wallw1.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "城頭");
	set("long", @LONG
狂風吹雪，捲起千堆銀屑。孤鴻翔空，拂亂萬裏雲空。“平地不見
雪，白沙入黃雲”，正是這種情況的真實寫照。遠處依稀可見一兩個在
當地被稱爲‘海子’的湖泊，在狂風、白雪、烈日的映照下，掛起點點
魚鱗之浪。
LONG );
	set("outdoors", "lingxiao");
	set("exits", ([
		"west"     : __DIR__"wallw2",
		"eastdown" : __DIR__"gate",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 1,
	])); 
	set("coor/x", -31010);
	set("coor/y", -8930);
	set("coor/z", 150);
	setup();
	replace_program(ROOM);
}

