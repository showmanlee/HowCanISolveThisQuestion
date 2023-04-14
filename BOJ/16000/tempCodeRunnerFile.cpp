		double a, p1, r, p2;
		cin >> a >> p1 >> r >> p2;
		double aa = a / p1;
		double rr = r * r * M_PI / p2;
		if (aa > rr) {
			cout << "Slice of pizza\n";
		} else {
			cout << "Whole pizza\n";
		}