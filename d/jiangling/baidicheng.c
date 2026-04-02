//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
  set ("short", "白帝城");
  set ("long", @LONG
白帝城是三峽的起點，位於長江北岸草堂河口，座落在名爲白帝山
的紫色丘陵上。它是一座美麗的山城。青蔥的白帝山象一塊渾然的翡翠，
紅牆綠瓦的白帝廟掩映在綠樹叢中。清晨，山城沐浴在緋紅的霞光裏，
好比在“彩雲間”一樣。白帝城自古有“詩城”之稱。杜甫曾有詩云：
白帝城中雲出門，白帝城下雨翻盆。高江急峽雷霆鬥，古木蒼藤日月昏。
李白、劉禹錫、陸遊、范成大等都曾在這裏留下足跡，寫了許多膾炙人
口的詩篇。東邊就是險峻的瞿塘峽了。
LONG);
	set("no_clean_up", 0);
	set("outdoors", "jiangling");
	set("exits", ([
                "east" : __DIR__"qutangxia",
                "north": __DIR__"shandao6",
	]));
  
	set("coor/x", -1520);
	set("coor/y", -2060);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
