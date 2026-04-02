//Room: /d/dali/dianchi.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","滇池");
	set("long",@LONG
滇池四周的山脈均屬崑崙山系，雲嶺山脈的東支逶迤南下，總稱烏蒙山，
有大小數十個山峯。湖身緊靠西山腳下，山環水抱，天光雲影，構成天然的
圖畫。滇池的“滇”在彝語中即是大壩子，兼司馬遷的《史記·西南夷列傳》
記載，在古代就是這一地區的最大的部族名稱，是名滇池。
LONG);
	set("outdoors", "dalic");
	set("exits",([ /* sizeof() == 1 */
	    "north"   : __DIR__"dasenlin",
	    "south"   : __DIR__"yanchi1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -35000);
	set("coor/y", -70300);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}