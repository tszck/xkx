//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "瞿塘峽");
	set ("long", @LONG
杜甫曾在詩中寫道：“白帝高爲三峽鎮，瞿塘險過百牢關”。從白
帝城向東，便進入長江三峽中最西面的瞿塘峽。它包括風箱峽和錯開峽
兩段水峽，在三峽中最短，卻最爲雄偉險峻。
LONG);
	set("outdoors", "jiangling");
	set("exits", ([
		"west" : __DIR__"baidicheng",
		"east" : __DIR__"wuxia",
	]));
  
	set("coor/x", -1510);
	set("coor/y", -2060);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
