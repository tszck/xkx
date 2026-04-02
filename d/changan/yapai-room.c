// /d/changan/yapai-room.c.

inherit  ROOM;

void  create  ()
{
	set  ("short",  "押牌房");
	set  ("long",  @LONG
屋子中間放着一張白玉桌，桌後一張鑲玉太師椅上坐着的就是莊家
了。你想和他玩玩麼？那麼，玩完你自個之前，想來還是先看看牆上釘
的牌子(paizi)吧。
LONG);

	set("item_desc",  (["paizi"  :  "

押牌規則：
一，只允許一個個和莊家玩遊戲。遊戲名稱叫二十一點。
二，先下注，至少一兩銀子，最多二十兩黃金。下注方法就是直接把錢給莊家。
三，要下一張牌(deal)。直到爆破二十一點。
四，在沒有爆破二十一點之前，可以亮牌(turn)。

注意事項：
一、相同點數時，莊家獲勝。玩家以二十一點獲勝時，獲雙倍賠償。
二、A 可以作爲一點計算，也可以做爲十一點計算。J、Q、K 做十點計算。
三、本賭場對玩家的一切損失概不負責。
四、銀票金票不適用此處。請勿使用，沒收不賠。

		\n"  ]));
	//for  look  something.

	set("exits",  
	([  //sizeof()  ==  4
		"north"  :  __DIR__"clubpoem",
	]));
	
	set("objects",  
	([  //sizeof()  ==  1
		"/d/city/npc/paitong"  :  1,
	]));

	set("no_fight",  1);
	set("no_beg",  1);
	set("no_magic",  1);
	set("no_clean_up",  1);
	set("coor/x", -5030);
	set("coor/y", 1000);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
