{
    description = "Develop in C";

    inputs = {
        nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
    };

    outputs = { self, nixpkgs }: 
    
    let
        system = "x86_64-linux";  
        pkgs = nixpkgs.legacyPackages.${system};
    in 
    {
        devShells.${system}.default = 
            pkgs.mkShell 
            {
                buildInputs = [ 
                    pkgs.valgrind
                    pkgs.gdb
                    pkgs.pkg-config
                    pkgs.neofetch
                    pkgs.gnumake
                    pkgs.doxygen
                ];
                shellHook = ''
                    echo "Hello, Mom!"
                    export TEST="ABC"
                '';
            };
    };
}

