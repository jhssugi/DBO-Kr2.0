CNtlTSTrigger
{
	sm = 1;
	sq = 1;
	qc = 7;
	rq = 0;
	tid = 2109;
	title = 210902;

	CNtlTSGroup
	{
		gid = 0;

		CDboTSContGAct
		{
			cid = 2;
			elnk = 252;
			nextlnk = 100;
			prelnk = "1;";

			CDboTSActNPCConv
			{
				conv = 210909;
				ctype = 1;
				idx = 3031104;
				taid = 2;
			}
			CDboTSActRegQInfo
			{
				cont = 210908;
				gtype = 1;
				area = 210901;
				goal = 210904;
				grade = 132203;
				rwd = 100;
				scitem = -1;
				sort = 210905;
				stype = 1;
				taid = 1;
				title = 210902;
			}
		}
		CDboTSContReward
		{
			canclnk = 255;
			cid = 100;
			rwdzeny = 0;
			desc = 210914;
			nextlnk = 254;
			rwdexp = 0;
			rwdtbl = 210901;
			rwdtype = 0;
			ltime = -1;
			prelnk = "2;";
			usetbl = 1;

			CDboTSClickNPC
			{
				npcidx = "3031215;";
			}
		}
		CDboTSContEnd
		{
			cid = 254;
			prelnk = "100;";
			type = 1;
		}
		CDboTSContProposal
		{
			cancellnk = 253;
			cid = 1;
			cont = 210908;
			gtype = 1;
			oklnk = 2;
			area = 210901;
			goal = 210904;
			sort = 210905;
			prelnk = "0;";
			ds = 1;
			grade = 132203;
			rwd = 100;
			title = 210902;
		}
		CDboTSContStart
		{
			cid = 0;
			stdiag = 210907;
			nolnk = 253;
			rm = 0;
			yeslnk = 1;

			CDboTSCheckLvl
			{
				maxlvl = 100;
				minlvl = 51;
			}
			CDboTSClickNPC
			{
				npcidx = "3031104;";
			}
			CDboTSCheckClrQst
			{
				flink = 1;
				flinknextqid = "2110;";
				not = 0;
			}
		}
		CDboTSContEnd
		{
			cid = 253;
			prelnk = "0;1;252;";
			type = 0;
		}
		CDboTSContGAct
		{
			cid = 252;
			elnk = 255;
			nextlnk = 253;
			prelnk = "2;";
		}
	}
}

