// This file is part of Bembel, the higher order C++ boundary element library.
// It was written as part of a cooperation of J. Doelz, H. Harbrecht, S. Kurz,
// M. Multerer, S. Schoeps, and F. Wolf at Technische Universtaet Darmstadt,
// Universitaet Basel, and Universita della Svizzera italiana, Lugano. This
// source code is subject to the GNU General Public License version 3 and
// provided WITHOUT ANY WARRANTY, see <http://www.bembel.eu> for further
// information.
#include "Spline.hpp"
#include "spltest.h"

namespace _SPLINE_IMPORT_TEST {

// inline std::string getGeomName() { return " NURBS sphere of p = 5"; }
inline std::vector<Spl::Patch> mkSphere() {
  Spl::Patch left, right, top, bot, front, back;

  Spl::makeFile("test.dat", 6);

  // define patches with temp mats that go out of scope

  std::vector<double> tempknt = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1};

  {
    Eigen::Matrix<double, 5, 5> X, Y, Z, ws;
    X << -0.577350269189626, -0.278838767912603, 0.000000000000000,
        0.278838767912603, 0.577350269189626, -0.632392158505876,
        -0.315090742770461, 0.000000000000000, 0.315090742770461,
        0.632392158505876, -0.647791890991355, -0.328648516366383,
        0.000000000000000, 0.328648516366383, 0.647791890991355,
        -0.632392158505876, -0.315090742770461, 0.000000000000000,
        0.315090742770461, 0.632392158505876, -0.577350269189626,
        -0.278838767912603, 0.000000000000000, 0.278838767912603,
        0.577350269189626;
    Y << 0.577350269189626, 0.632392158505876, 0.647791890991355,
        0.632392158505876, 0.577350269189626, 0.632392158505876,
        0.762259526419164, 0.804938188574224, 0.762259526419164,
        0.632392158505876, 0.647791890991355, 0.804938188574224,
        0.859116756396542, 0.804938188574224, 0.647791890991355,
        0.632392158505876, 0.762259526419164, 0.804938188574224,
        0.762259526419164, 0.632392158505876, 0.577350269189626,
        0.632392158505876, 0.647791890991355, 0.632392158505876,
        0.577350269189626;
    Z << -0.577350269189626, -0.632392158505876, -0.647791890991355,
        -0.632392158505876, -0.577350269189626, -0.278838767912603,
        -0.315090742770461, -0.328648516366383, -0.315090742770461,
        -0.278838767912603, -0.000000000000000, -0.000000000000000,
        -0.000000000000000, -0.000000000000000, -0.000000000000000,
        0.278838767912603, 0.315090742770461, 0.328648516366383,
        0.315090742770461, 0.278838767912603, 0.577350269189626,
        0.632392158505876, 0.647791890991355, 0.632392158505876,
        0.577350269189626;
    ws << 1.000000000000000, 0.891211203608397, 0.859116756396542,
        0.891211203608397, 1.000000000000000, 0.891211203608397,
        0.762259526419164, 0.718665173540050, 0.762259526419164,
        0.891211203608397, 0.859116756396542, 0.718665173540050,
        0.671272431591931, 0.718665173540050, 0.859116756396542,
        0.891211203608397, 0.762259526419164, 0.718665173540050,
        0.762259526419164, 0.891211203608397, 1.000000000000000,
        0.891211203608397, 0.859116756396542, 0.891211203608397,
        1.000000000000000;

    X = X.rowwise().reverse().eval();
    Y = Y.rowwise().reverse().eval();
    Z = Z.rowwise().reverse().eval();
    ws = ws.rowwise().reverse().eval();

    std::vector<Eigen::Matrix<double, -1, -1>> tempctrl = {X, Y, Z, ws};
    left.initHom(tempctrl, tempknt, tempknt);
    // left.turnNormal();
    Spl::writePatch("test.dat", 0, tempctrl, tempknt, tempknt);
  }

  // std::cout<< "Front\n";
  {
    Eigen::Matrix<double, 5, 5> X, Y, Z, ws;

    X << -0.577350269189626, -0.632392158505876, -0.647791890991355,
        -0.632392158505876, -0.577350269189626, -0.632392158505876,
        -0.762259526419164, -0.804938188574224, -0.762259526419164,
        -0.632392158505876, -0.647791890991355, -0.804938188574224,
        -0.859116756396542, -0.804938188574224, -0.647791890991355,
        -0.632392158505876, -0.762259526419164, -0.804938188574224,
        -0.762259526419164, -0.632392158505876, -0.577350269189626,
        -0.632392158505876, -0.647791890991355, -0.632392158505876,
        -0.577350269189626;
    Y << -0.577350269189626, -0.278838767912603, 0.000000000000000,
        0.278838767912603, 0.577350269189626, -0.632392158505876,
        -0.315090742770461, 0.000000000000000, 0.315090742770461,
        0.632392158505876, -0.647791890991355, -0.328648516366383,
        0.000000000000000, 0.328648516366383, 0.647791890991355,
        -0.632392158505876, -0.315090742770461, 0.000000000000000,
        0.315090742770461, 0.632392158505876, -0.577350269189626,
        -0.278838767912603, 0.000000000000000, 0.278838767912603,
        0.577350269189626;
    Z << -0.577350269189626, -0.632392158505876, -0.647791890991355,
        -0.632392158505876, -0.577350269189626, -0.278838767912603,
        -0.315090742770461, -0.328648516366383, -0.315090742770461,
        -0.278838767912603, -0.000000000000000, -0.000000000000000,
        -0.000000000000000, -0.000000000000000, -0.000000000000000,
        0.278838767912603, 0.315090742770461, 0.328648516366383,
        0.315090742770461, 0.278838767912603, 0.577350269189626,
        0.632392158505876, 0.647791890991355, 0.632392158505876,
        0.577350269189626;
    ws << 1.000000000000000, 0.891211203608397, 0.859116756396542,
        0.891211203608397, 1.000000000000000, 0.891211203608397,
        0.762259526419164, 0.718665173540050, 0.762259526419164,
        0.891211203608397, 0.859116756396542, 0.718665173540050,
        0.671272431591931, 0.718665173540050, 0.859116756396542,
        0.891211203608397, 0.762259526419164, 0.718665173540050,
        0.762259526419164, 0.891211203608397, 1.000000000000000,
        0.891211203608397, 0.859116756396542, 0.891211203608397,
        1.000000000000000;

    X = X.rowwise().reverse().eval();
    Y = Y.rowwise().reverse().eval();
    Z = Z.rowwise().reverse().eval();
    ws = ws.rowwise().reverse().eval();

    std::vector<Eigen::Matrix<double, -1, -1>> tempctrl = {X, Y, Z, ws};
    front.initHom(tempctrl, tempknt, tempknt);
    Spl::writePatch("test.dat", 1, tempctrl, tempknt, tempknt);
  }

  // // std::cout<< "Right\n";
  {
    Eigen::Matrix<double, 5, 5> X, Y, Z, ws;
    X << -0.577350269189626, -0.278838767912603, -0.000000000000000,
        0.278838767912603, 0.577350269189626, -0.632392158505876,
        -0.315090742770461, -0.000000000000000, 0.315090742770461,
        0.632392158505876, -0.647791890991355, -0.328648516366383,
        -0.000000000000000, 0.328648516366383, 0.647791890991355,
        -0.632392158505876, -0.315090742770461, -0.000000000000000,
        0.315090742770461, 0.632392158505876, -0.577350269189626,
        -0.278838767912603, -0.000000000000000, 0.278838767912603,
        0.577350269189626;
    Y << -0.577350269189626, -0.632392158505876, -0.647791890991355,
        -0.632392158505876, -0.577350269189626, -0.632392158505876,
        -0.762259526419164, -0.804938188574224, -0.762259526419164,
        -0.632392158505876, -0.647791890991355, -0.804938188574224,
        -0.859116756396542, -0.804938188574224, -0.647791890991355,
        -0.632392158505876, -0.762259526419164, -0.804938188574224,
        -0.762259526419164, -0.632392158505876, -0.577350269189626,
        -0.632392158505876, -0.647791890991355, -0.632392158505876,
        -0.577350269189626;
    Z << -0.577350269189626, -0.632392158505876, -0.647791890991355,
        -0.632392158505876, -0.577350269189626, -0.278838767912603,
        -0.315090742770461, -0.328648516366383, -0.315090742770461,
        -0.278838767912603, -0.000000000000000, -0.000000000000000,
        -0.000000000000000, -0.000000000000000, -0.000000000000000,
        0.278838767912603, 0.315090742770461, 0.328648516366383,
        0.315090742770461, 0.278838767912603, 0.577350269189626,
        0.632392158505876, 0.647791890991355, 0.632392158505876,
        0.577350269189626;
    ws << 1.000000000000000, 0.891211203608397, 0.859116756396542,
        0.891211203608397, 1.000000000000000, 0.891211203608397,
        0.762259526419164, 0.718665173540050, 0.762259526419164,
        0.891211203608397, 0.859116756396542, 0.718665173540050,
        0.671272431591931, 0.718665173540050, 0.859116756396542,
        0.891211203608397, 0.762259526419164, 0.718665173540050,
        0.762259526419164, 0.891211203608397, 1.000000000000000,
        0.891211203608397, 0.859116756396542, 0.891211203608397,
        1.000000000000000;
    X = X.transpose().eval();
    Y = Y.transpose().eval();
    Z = Z.transpose().eval();

    X = X.rowwise().reverse().eval();
    Y = Y.rowwise().reverse().eval();
    Z = Z.rowwise().reverse().eval();
    ws = ws.rowwise().reverse().eval();

    std::vector<Eigen::Matrix<double, -1, -1>> tempctrl = {X, Y, Z, ws};
    right.initHom(tempctrl, tempknt, tempknt);
    Spl::writePatch("test.dat", 2, tempctrl, tempknt, tempknt);
  }

  // // std::cout<< "Back\n";
  {
    Eigen::Matrix<double, 5, 5> X, Y, Z, ws;
    X << 0.577350269189626, 0.632392158505876, 0.647791890991355,
        0.632392158505876, 0.577350269189626, 0.632392158505876,
        0.762259526419164, 0.804938188574224, 0.762259526419164,
        0.632392158505876, 0.647791890991355, 0.804938188574224,
        0.859116756396542, 0.804938188574224, 0.647791890991355,
        0.632392158505876, 0.762259526419164, 0.804938188574224,
        0.762259526419164, 0.632392158505876, 0.577350269189626,
        0.632392158505876, 0.647791890991355, 0.632392158505876,
        0.577350269189626;
    Y << -0.577350269189626, -0.278838767912603, -0.000000000000000,
        0.278838767912602, 0.577350269189626, -0.632392158505876,
        -0.315090742770461, -0.000000000000000, 0.315090742770461,
        0.632392158505876, -0.647791890991355, -0.328648516366384,
        -0.000000000000000, 0.328648516366383, 0.647791890991355,
        -0.632392158505876, -0.315090742770461, -0.000000000000000,
        0.315090742770461, 0.632392158505876, -0.577350269189626,
        -0.278838767912603, -0.000000000000000, 0.278838767912602,
        0.577350269189626;
    Z << -0.577350269189626, -0.632392158505876, -0.647791890991355,
        -0.632392158505876, -0.577350269189626, -0.278838767912603,
        -0.315090742770461, -0.328648516366383, -0.315090742770461,
        -0.278838767912603, -0.000000000000000, -0.000000000000000,
        -0.000000000000000, -0.000000000000000, -0.000000000000000,
        0.278838767912603, 0.315090742770461, 0.328648516366383,
        0.315090742770461, 0.278838767912603, 0.577350269189626,
        0.632392158505876, 0.647791890991355, 0.632392158505876,
        0.577350269189626;
    ws << 1.000000000000000, 0.891211203608397, 0.859116756396542,
        0.891211203608397, 1.000000000000000, 0.891211203608397,
        0.762259526419164, 0.718665173540050, 0.762259526419164,
        0.891211203608397, 0.859116756396542, 0.718665173540050,
        0.671272431591931, 0.718665173540050, 0.859116756396542,
        0.891211203608397, 0.762259526419164, 0.718665173540050,
        0.762259526419164, 0.891211203608397, 1.000000000000000,
        0.891211203608397, 0.859116756396542, 0.891211203608397,
        1.000000000000000;

    X = X.transpose().eval();
    Y = Y.transpose().eval();
    Z = Z.transpose().eval();

    X = X.rowwise().reverse().eval();
    Y = Y.rowwise().reverse().eval();
    Z = Z.rowwise().reverse().eval();
    ws = ws.rowwise().reverse().eval();

    std::vector<Eigen::Matrix<double, -1, -1>> tempctrl = {X, Y, Z, ws};
    back.initHom(tempctrl, tempknt, tempknt);
    Spl::writePatch("test.dat", 3, tempctrl, tempknt, tempknt);
  }

  // // std::cout<< "Top\n";
  {
    Eigen::Matrix<double, 5, 5> X, Y, Z, ws;
    X << -0.577350269189626, -0.278838767912603, 0.000000000000000,
        0.278838767912603, 0.577350269189626, -0.632392158505876,
        -0.315090742770461, 0.000000000000000, 0.315090742770461,
        0.632392158505876, -0.647791890991355, -0.328648516366383,
        0.000000000000000, 0.328648516366383, 0.647791890991355,
        -0.632392158505876, -0.315090742770461, 0.000000000000000,
        0.315090742770461, 0.632392158505876, -0.577350269189626,
        -0.278838767912603, 0.000000000000000, 0.278838767912603,
        0.577350269189626;
    Y << -0.577350269189626, -0.632392158505876, -0.647791890991355,
        -0.632392158505876, -0.577350269189626, -0.278838767912603,
        -0.315090742770461, -0.328648516366383, -0.315090742770461,
        -0.278838767912603, 0.000000000000000, 0.000000000000000,
        0.000000000000000, 0.000000000000000, 0.000000000000000,
        0.278838767912603, 0.315090742770461, 0.328648516366383,
        0.315090742770461, 0.278838767912603, 0.577350269189626,
        0.632392158505876, 0.647791890991355, 0.632392158505876,
        0.577350269189626;
    Z << 0.577350269189626, 0.632392158505876, 0.647791890991355,
        0.632392158505876, 0.577350269189626, 0.632392158505876,
        0.762259526419164, 0.804938188574224, 0.762259526419164,
        0.632392158505876, 0.647791890991355, 0.804938188574224,
        0.859116756396542, 0.804938188574224, 0.647791890991355,
        0.632392158505876, 0.762259526419164, 0.804938188574224,
        0.762259526419164, 0.632392158505876, 0.577350269189626,
        0.632392158505876, 0.647791890991355, 0.632392158505876,
        0.577350269189626;
    ws << 1.000000000000000, 0.891211203608397, 0.859116756396542,
        0.891211203608397, 1.000000000000000, 0.891211203608397,
        0.762259526419164, 0.718665173540050, 0.762259526419164,
        0.891211203608397, 0.859116756396542, 0.718665173540050,
        0.671272431591931, 0.718665173540050, 0.859116756396542,
        0.891211203608397, 0.762259526419164, 0.718665173540050,
        0.762259526419164, 0.891211203608397, 1.000000000000000,
        0.891211203608397, 0.859116756396542, 0.891211203608397,
        1.000000000000000;
    X = X.transpose().eval();
    Y = Y.transpose().eval();
    Z = Z.transpose().eval();

    X = X.rowwise().reverse().eval();
    Y = Y.rowwise().reverse().eval();
    Z = Z.rowwise().reverse().eval();
    ws = ws.rowwise().reverse().eval();

    std::vector<Eigen::Matrix<double, -1, -1>> tempctrl = {X, Y, Z, ws};
    top.initHom(tempctrl, tempknt, tempknt);
    Spl::writePatch("test.dat", 4, tempctrl, tempknt, tempknt);
  }

  // std::cout <<  "Bot\n";
  {
    Eigen::Matrix<double, 5, 5> X, Y, Z, ws;
    X << -0.577350269189626, -0.278838767912603, 0.000000000000000,
        0.278838767912603, 0.577350269189626, -0.632392158505876,
        -0.315090742770461, 0.000000000000000, 0.315090742770461,
        0.632392158505876, -0.647791890991355, -0.328648516366383,
        0.000000000000000, 0.328648516366383, 0.647791890991355,
        -0.632392158505876, -0.315090742770461, 0.000000000000000,
        0.315090742770461, 0.632392158505876, -0.577350269189626,
        -0.278838767912603, 0.000000000000000, 0.278838767912603,
        0.577350269189626;

    // Y << 0.577350269189626, 0.632392158505876, 0.647791890991355,
    //     0.632392158505876, 0.577350269189626, 0.278838767912603,
    //     0.315090742770461, 0.328648516366383, 0.315090742770461,
    //     0.278838767912603, 0.000000000000000, 0.000000000000000,
    //     0.000000000000000, 0.000000000000000, 0.000000000000000,
    //     -0.278838767912603, -0.315090742770461, -0.328648516366383,
    //     -0.315090742770461, -0.278838767912603, -0.577350269189626,
    //     -0.632392158505876, -0.647791890991355, -0.632392158505876,
    //     -0.577350269189626;
    Y << -0.577350269189626, -0.632392158505876, -0.647791890991355,
        -0.632392158505876, -0.577350269189626, -0.278838767912603,
        -0.315090742770461, -0.328648516366383, -0.315090742770461,
        -0.278838767912603, 0.000000000000000, 0.000000000000000,
        0.000000000000000, 0.000000000000000, 0.000000000000000,
        0.278838767912603, 0.315090742770461, 0.328648516366383,
        0.315090742770461, 0.278838767912603, 0.577350269189626,
        0.632392158505876, 0.647791890991355, 0.632392158505876,
        0.577350269189626;

    Z << -0.577350269189626, -0.632392158505876, -0.647791890991355,
        -0.632392158505876, -0.577350269189626, -0.632392158505876,
        -0.762259526419164, -0.804938188574224, -0.762259526419164,
        -0.632392158505876, -0.647791890991355, -0.804938188574224,
        -0.859116756396542, -0.804938188574224, -0.647791890991355,
        -0.632392158505876, -0.762259526419164, -0.804938188574224,
        -0.762259526419164, -0.632392158505876, -0.577350269189626,
        -0.632392158505876, -0.647791890991355, -0.632392158505876,
        -0.577350269189626;
    ws << 1.000000000000000, 0.891211203608397, 0.859116756396542,
        0.891211203608397, 1.000000000000000, 0.891211203608397,
        0.762259526419164, 0.718665173540050, 0.762259526419164,
        0.891211203608397, 0.859116756396542, 0.718665173540050,
        0.671272431591931, 0.718665173540050, 0.859116756396542,
        0.891211203608397, 0.762259526419164, 0.718665173540050,
        0.762259526419164, 0.891211203608397, 1.000000000000000,
        0.891211203608397, 0.859116756396542, 0.891211203608397,
        1.000000000000000;

    X = X.rowwise().reverse().eval();
    Y = Y.rowwise().reverse().eval();
    Z = Z.rowwise().reverse().eval();
    ws = ws.rowwise().reverse().eval();

    std::vector<Eigen::Matrix<double, -1, -1>> tempctrl = {X, Y, Z, ws};
    bot.initHom(tempctrl, tempknt, tempknt);
    Spl::writePatch("test.dat", 5, tempctrl, tempknt, tempknt);
  }

  //  // end scope of temp vecs

  std::vector<Spl::Patch> out = {left, front, right, back, top, bot};

  // out.push_back(left);

  // std::cout << out[0].ctrlpts[0] << "\n";

  // std::cout << "Out\n";

  return out;
}

}  // namespace _SPLINE_IMPORT_TEST
int test_import() {
  std::vector<Spl::Patch> geom1 = _SPLINE_IMPORT_TEST::mkSphere();
  std::vector<Spl::Patch> geom2 =
      Spl::PatchShredder(Spl::loadGeometryFile("test.dat"));
  const int sz = geom1.size();
  if (sz != geom2.size()) {
    return 1;
  }

  std::vector<double> pts;
  pts.reserve(101);
  for (int i = 0; i < 101; i++) pts.push_back(i * 0.01);

  for (int i = 0; i < 1; i++)
    for (auto x : pts)
      for (auto y : pts) {
        if ((geom1[i].eval(x, y) - geom2[i].eval(x, y)).norm() > 1e-14) {
          return 1;
        }
      }

  return 0;
}