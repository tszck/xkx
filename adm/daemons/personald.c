// personald.c 外貌

#include <ansi.h>

string query_personal(string gender,int per)
{
//	object obj=this_player();

	if ( gender == "男性"||gender == "無性" ) {
		switch(per)
		{
			case 39: return HIG"現在神清氣爽，骨格清奇，顧盼之間，神采飛揚，恍若仙人。\n"NOR;
			case 38: return HIG"現在丰神俊朗，長身玉立，宛如玉樹臨風。\n"NOR;
			case 37: return HIG"現在飄逸出塵，瀟灑絕倫，貌似潘安。\n"NOR;
			case 36: return HIG"現在面如美玉，粉妝玉琢，骨格清奇，俊美不凡。\n"NOR;
			case 35: return HIG"現在丰神如玉，目似朗星，令人過目難忘。\n"NOR;
			case 34: return HIY"現在粉面朱脣，身姿俊俏，舉止風流無限。\n"NOR;
			case 33: return HIY"現在雙目如星，眉梢傳情，所見者無不為之心動。\n"NOR;
			case 32: return HIY"現在舉動如行雲游水，獨蘊風情，吸引所有異性目光。\n"NOR;
			case 31: return HIY"現在雙眼光華瑩潤，透出攝人心魄的光芒。\n"NOR;
			case 30: return HIY"生得英俊瀟灑，氣宇軒昂，風度翩翩，風流倜儻。\n"NOR;
			case 29: return MAG"生得目似點漆，面目俊朗，高大挺俊，令人心動。\n"NOR;
			case 28: return MAG"生得面若秋月，儒雅斯文，舉止適度，儀表堂堂。\n"NOR;
			case 27: return MAG"生得劍眉星目，英姿勃勃，儀表不凡。\n"NOR;
			case 26: return MAG"生得滿面濃髯，環眼豹鼻，威風凜凜，讓人傾倒。\n"NOR;
			case 25: return MAG"生得眉如雙劍，眼如明星，英挺出眾。\n"NOR;
			case 24: return CYN"生得虎背熊腰，壯健有力，英姿勃發。\n"NOR;
			case 23: return CYN"生得膚色白皙，紅脣墨髮，斯文有禮。\n"NOR;
			case 22: return CYN"生得濃眉大眼，高大挺拔，氣宇軒昂。\n"NOR;
			case 21: return CYN"生得鼻直口方，線條分明，顯出剛毅性格。\n"NOR;
			case 20: return CYN"生得眉目清秀，端正大方，一表人才。\n"NOR;
			case 19: return YEL"生得腰圓背厚，面闊口方，骨格不凡。\n"NOR;
			case 18: return YEL"生得相貌平平，不會給人留下什麼印象，沒什麼好看的。\n"NOR;
			case 17: return YEL"生得膀大腰圓，滿臉橫肉，惡形惡相。\n"NOR;
			case 16: return YEL"生得獐頭鼠須，讓人一看就不生好感。\n"NOR;
			case 15: return YEL"生得面頰深陷，瘦如枯骨，讓人要發惡夢。\n"NOR;
			case 14: return RED"生得肥頭大耳，腹圓如鼓，手腳短粗，令人發笑。\n"NOR;
			case 13: return RED"生得賊眉鼠眼，身高三尺，宛若猴狀。\n"NOR;
			case 12: return RED"生得面如桔皮，頭腫如豬，讓人不想再看第二眼。\n"NOR;
			case 11: return RED"生得呲牙咧嘴，黑如鍋底，奇醜無比。\n"NOR;
			default:
				if (per <= 10 ) return RED"生得眉歪眼斜，瘌頭癬腳，不象人樣。\n"NOR;
				if (per >= 40 ) return HIW"現在一派神人氣度，仙風道骨，舉止出塵。\n"NOR;
		}
	}
	if ( gender == "女性"){
		switch(per)
		{
			case 40: return HIW"現在宛如玉雕冰塑，似夢似幻，已不再是凡間人物。\n"NOR;
			case 39: return HIG"現在美若天仙，不沾一絲煙塵。\n"NOR;
			case 38: return HIG"現在燦若明霞，寶潤如玉，恍如神妃仙子。\n"NOR;
			case 37: return HIG"清麗絕俗，風姿動人。有沉魚落雁之容，避月羞花之貌！\n"NOR;
			case 36: return HIG"現在氣質美如蘭，才華馥比仙，令人見之忘俗。\n"NOR;
			case 35: return HIY"俏臉生春，妙目含情，顧盼神飛，輕輕一笑，不覺讓人怦然心動。\n"NOR;
			case 34: return HIY"現在豐潤嫩白，嬰桃小口，眉目含情，彷彿太真重臨。\n"NOR;
			case 33: return HIY"現在鮮豔嫵媚，嫋娜風流，柔媚姣俏，粉光脂豔。\n"NOR;
			case 32: return HIY"現在鬢若刀裁，眉如墨畫，面如桃瓣，目若秋波。\n"NOR;
			case 31: return HIY"現在鳳眼柳眉，粉面含春，丹脣貝齒，轉盼多情。\n"NOR;
			case 30: return HIM"現在眉目如畫，肌膚勝雪，真可謂閉月羞花。\n"NOR;
			case 29: return HIM"現在嬌若春花，媚如秋月，真的能沉魚落雁。。\n"NOR;
			case 28: return HIM"膚如凝脂，眉目如畫，風情萬種，楚楚動人。當真是我見猶憐！\n"NOR;
			case 27: return HIM"生得閒靜如姣花照水，行動似弱柳扶風，體態萬千。\n"NOR;
			case 26: return HIM"生得嬌小玲瓏，宛如飛燕再世，楚楚動人。真是玉面嬌容花含露，纖足細腰柳帶煙。\n"NOR;
			case 25: return MAG"生得鴨蛋秀臉，俊眼修眉，黑髮如瀑，風情萬種。\n"NOR;
			case 24: return MAG"容色秀麗，面帶暈紅，眼含秋波。舉手投足之間，確有一番風韻。\n"NOR;
			case 23: return MAG"生得削肩細腰，身材苗條，嬌媚動人，顧盼神飛。\n"NOR;
			case 22: return MAG"生得豐胸細腰，妖嬈多姿，讓人一看就心跳不已。\n"NOR;
			case 21: return MAG"氣質高雅，面目姣好，雖算不上絕世佳人，也頗有幾份姿色。\n";
			case 20: return CYN"生得粉嫩白至，如芍藥籠煙，霧裏看花。\n"NOR;
			case 19: return CYN"生得腮凝新荔，目若秋水，千嬌百媚。鮮豔妍媚，肌膚瑩透，引人遐思。\n"NOR;
			case 18: return CYN"生得如梨花帶露，清新秀麗。巧笑嫣然，宛約可人。\n"NOR;
			case 17: return CYN"生得風姿楚楚，明麗動人。肌膚微豐，雅淡溫宛，清新可人。\n"NOR;
			case 16: return YEL"生得雖不標緻，倒也白淨，有些動人之處。\n"NOR;
			case 15: return YEL"生得身材瘦小，肌膚無光，兩眼無神。\n"NOR;
			case 14: return YEL"生得幹黃枯瘦，臉色臘黃，毫無女人味。\n"NOR;
			case 13: return RED"生得眼小如豆，眉毛稀疏，手如猴爪，不成人樣。\n"NOR;
			case 12: return RED"生得八字眉，三角眼，雞皮黃髮，讓人一見就想吐。\n"NOR;
			case 11: return RED"生得歪鼻斜眼，臉色灰敗，直如鬼怪一般。\n"NOR;
			default:
				if (per > 40) return HIW"有傾國傾城之貌，容色麗都，嬌豔絕倫，堪稱人間仙子！\n長髮如雲，肌膚勝雪，風華絕代，不知傾倒了多少英雄豪傑。\n"NOR;
				if (per <= 10) return RED"生得醜如無鹽，狀如夜叉，女人長成這樣真是人生悲劇。\n"NOR;
		}
	}
}
