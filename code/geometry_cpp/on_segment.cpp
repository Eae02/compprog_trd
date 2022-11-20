bool onSegment(ipoint s, ipoint e, ipoint p) { return s.cross(e, p) == 0 && (s - p).dot(e - p) <= 0; }
