// Room : /d/chengdu/wuhouci.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
        set("short", "武侯祠");
        set("long", @LONG

          丞相祠堂何處尋？錦官城外柏森森。
          映階碧草自春色，隔葉黃鸝空好音。
          三顧頻煩天下計，兩朝開濟老臣心。
          出師未捷身先死，長使英雄淚滿襟。

    這裏就是被川人敬仰的武侯祠。這裏安葬着三國時代的一代賢臣諸
葛亮，常有成都本地人和遊客前來參拜。四周參天大樹環繞着巨大陵墓，
大樹上不時傳來幾聲畫眉鳥清脆的叫聲。你念着“出師未捷身先死”，
心中不由得一陣黯然。西面有座陵墓。
LONG	);
        set("exits", ([
		"west"      : __DIR__"lingmu",
		"northup"   : __DIR__"liubeidian",
		"southeast" : __DIR__"wuhoucigate",
	]));
        set("outdoors", "chengdu");
        set("coor/x", -8070);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

